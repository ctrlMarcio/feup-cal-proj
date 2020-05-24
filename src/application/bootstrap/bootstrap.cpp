#include <dirent.h>
#include <thread>

#include "../../exception/invalid_location_exception.h"
#include "../../exception/invalid_directory_exception.h"
#include "bootstrap.h"

const std::string Bootstrap::NODES_FILE = "nodes.txt";

const std::string Bootstrap::EDGES_FILE = "edges.txt";

Bootstrap::Bootstrap(const std::string &directory) {
    this->appendToGraph(directory, "Portugal");
}

void Bootstrap::appendToGraph(const std::string &directory, const std::string &country) {
    DIR *dir;

    if ((dir = opendir(directory.c_str())) != nullptr) {
        struct dirent *ent;
        long before = graph.verticesCount();

        std::vector<std::thread> threads;
        std::mutex mutex;

        while ((ent = readdir(dir)) != nullptr) {
            // enters in each of the cities
            std::string city(ent->d_name);

            if (city == "." || city == ".." || city == country)
                continue;

            std::string path = directory + "/" + city;

            if (opendir(path.c_str()) != nullptr) {
                std::thread t(&Bootstrap::readDir, this, city, path, &mutex);
                threads.push_back(std::move(t));

            } else {
                cerr << path << endl;
                throw InvalidDirectoryException(path);
            }
        }

        for (std::thread &thread : threads)
            thread.join();

        std::string countryDir = directory + "/" + country;
        // reads the country only in the end
        if (opendir(countryDir.c_str()) != nullptr) {
            std::string nodesFile = countryDir + "/" + NODES_FILE;
            std::string edgesFile = countryDir + "/" + EDGES_FILE;

            long old = graph.verticesCount();
            cout << "Reading remaining from " << country << "." << endl;
            this->append(nodesFile, edgesFile, country);
            cout << "Read remaining " << graph.verticesCount() - old << " nodes from " << country << "." << endl;
        }

        closedir(dir);

        cout << "\rRead a total of " << graph.verticesCount() - before << " nodes from " << country << "." << endl;
    } else {
        cerr << directory << endl;
        throw InvalidDirectoryException(directory);
    }
}

void Bootstrap::readDir(const string &city, const string &path, std::mutex *mutex) {
    string nodesFile = path + "/" + NODES_FILE;
    string edgesFile = path + "/" + EDGES_FILE;

    cout << "Reading " << city << "." << endl;
    this->append(nodesFile, edgesFile, city, mutex);
    cout << "Read " << city << "." << endl;
}

Company Bootstrap::buildCompany(const std::string &name, long locationId, long vehicleNumber) {
    Location tmp(locationId, "", 0, 0);
    try {
        auto vertex = graph.getVertex(tmp);

        Location location = vertex.get();

        Company company(name, location, std::move(this->graph), vehicleNumber);
        return company;
    } catch (InvalidVertexException &) {
        cerr << locationId << endl;
        throw InvalidLocationException(locationId, "Location does not exist.");
    }
}

void
Bootstrap::readNodes(const std::string &fileName, const std::string &city, std::mutex *mutex) {
    std::ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        throw InvalidFileException(fileName);
    }

    std::string line;
    std::getline(file, line); // reads the first, useless line

    while (std::getline(file, line)) {
        // example: (301415137, 546146.1558010778, 4601058.475980306, 41.5598669, -8.446596)

        if (line[0] == '#') continue;

        // gets all elements
        std::vector<std::string> elements = string_util::split(line, DELIMITER);
        bool isComplete = elements.size() == 5;

        std::string idStr = elements[0];    // (301415137
        std::string xStr = elements[1];     //  546146.1558010778
        std::string yStr = elements[2];     //  4601058.475980306
        std::string latStr;
        std::string lonStr;

        if (isComplete) {
            // TODO
            latStr = elements[4];   //  41.5598669
            lonStr = elements[3];   //  -8.446596)
        }

        // removes the clutter in the strings
        idStr = idStr.substr(1, idStr.size() - 1);  // 301415137

        if (isComplete)
            lonStr = lonStr.substr(0, lonStr.size() - 1); // -8.44659
        else
            yStr = yStr.substr(0, yStr.size() - 1);

        Location location;

        // casts to numbers
        long id = stol(idStr);
        double x = stod(xStr);
        double y = stod(yStr);

        if (isComplete) {
            double lat = stod(latStr);
            double lon = stod(lonStr);

            // creates a location
            location = Location(id, city, x, y, lat, lon);
        } else {
            location = Location(id, city, x, y);
        }

        // add to the graph
        if (mutex) mutex->lock();
        graph.add(location);
        if (mutex) mutex->unlock();
    }

    file.close();
}

bool Bootstrap::readEdges(const string &fileName, std::mutex *mutex) {
    bool allOk = true;

    std::ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        throw InvalidFileException(fileName);
    }

    std::string line;
    std::getline(file, line); // reads the first, useless line

    while (std::getline(file, line)) {
        // example: (384994721, 384994722)

        if (line[0] == '#') continue;

        // gets all elements
        std::vector<std::string> elements = string_util::split(line, DELIMITER);
        std::string srcStr = elements[0];   // (384994721
        std::string dstStr = elements[1];   //  384994722)

        // removes the clutter in the strings
        srcStr = srcStr.substr(1, srcStr.size() - 1);   // 384994721
        dstStr = dstStr.substr(0, dstStr.size() - 1);   // 384994722

        // casts to numbers
        long srcId = stol(srcStr);
        long dstId = stol(dstStr);

        // creates temporary locations to search for the real ones
        // location's "==" compares only the IDs
        Location tmpSrc(srcId, "", 0, 0);
        Location tmpDst(dstId, "", 0, 0);

        // gets the real locations
        try {
            auto src = graph.getVertex(tmpSrc);
            auto dst = graph.getVertex(tmpDst);

            // adds the edge
            if (mutex) mutex->lock();
            graph.add(src.get(), dst.get(), 1);
            //graph.add(dst.get(), src.get(), 1);
            if (mutex) mutex->unlock();
        } catch (InvalidVertexException &) {
            allOk = false;
            cout << "bro" << endl;
        }
    }

    file.close();

    return allOk;
}

void Bootstrap::append(const std::string &nodesFile, const std::string &edgesFile,
                       const std::string &city, std::mutex *mutex) {
    try {
        this->readNodes(nodesFile, city, mutex);
    } catch (InvalidFileException &e) {
        cout << "Can't append from " << city << "." << endl;
        return;
    }
    try {
        this->readEdges(edgesFile, mutex);
    } catch (InvalidFileException &e) {
        cerr << "Invalid edges file " << edgesFile << " after reading the nodes. Aborting." << endl;
        throw e;
    }
}
