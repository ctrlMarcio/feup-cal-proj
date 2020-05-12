#include <dirent.h>
#include <thread>

#include "../../exception/invalid_location_exception.h"
#include "../../exception/invalid_directory_exception.h"
#include "bootstrap.h"

const std::string Bootstrap::NODES_FILE = "nodes.txt";

const std::string Bootstrap::EDGES_FILE = "edges.txt";

Bootstrap::Bootstrap(const std::string& directory) {
    this->appendToGraph(directory, "Portugal");
}

void Bootstrap::appendToGraph(const std::string &directory, const std::string &country) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (directory.c_str())) != nullptr) {

        long before = graph.nodesAmount();

        std::vector<std::thread> threads;
        std::mutex mutex;

        while ((ent = readdir(dir)) != nullptr) {
            // enters in each of the cities
            std::string city(ent->d_name);

            if (city == "." || city == ".." || city == country)
                continue;

            std::string path = directory + "/" + city;

            if (opendir (path.c_str()) != nullptr) {

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
        if (opendir (countryDir.c_str()) != nullptr) {
            std::string nodesFile = countryDir + "/" + NODES_FILE;
            std::string edgesFile = countryDir + "/" + EDGES_FILE;

            long old = graph.nodesAmount();
            cout << "Reading remaining from " << country << "." << endl;
            this->graph.append(nodesFile, edgesFile, country);
            cout << "Read remaining " << graph.nodesAmount() - old << " nodes from " << country << "." << endl;
        } else {
            cout << "Can't append remaining from " << countryDir << "." << endl;
        }

        closedir(dir);

        cout << "\rRead a total of " << graph.nodesAmount() - before << " from " << country << "." << endl;
    } else {
        cerr << directory << endl;
        throw InvalidDirectoryException(directory);
    }
}

void Bootstrap::readDir(const string &city, const string &path, std::mutex *mutex) {
    string nodesFile = path + "/" + NODES_FILE;
    string edgesFile = path + "/" + EDGES_FILE;

    cout << "Reading " << city << "." << endl;
    this->graph.append(nodesFile, edgesFile, city, mutex);
    cout << "Read " << city << "." << endl;
}

Company Bootstrap::buildCompany(const std::string &name, long locationId, long vehicleNumber) {
    Location tmp(locationId, "", 0, 0);
    auto vertex = graph.findVertex(tmp);

    if (vertex == nullptr) {
        cerr << locationId << endl;
        throw InvalidLocationException(locationId, "Location does not exist.");
    }

    Location location = vertex->getInfo();

    Company company(name, location, this->graph, vehicleNumber);
    return company;
}
