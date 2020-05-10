#include <dirent.h>

#include "../../exception/invalid_location_exception.h"
#include "../../exception/invalid_directory_exception.h"
#include "bootstrap.h"


Bootstrap::Bootstrap(const std::string& directory) {
    this->appendToGraph(directory);
}

void Bootstrap::appendToGraph(const std::string &directory) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (directory.c_str())) != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            // enters in each of the cities
            std::string city(ent->d_name);

            if (city == "." || city == ".." || city == "Portugal") // TODO read country differently
                continue;

            // TODO thread

            std::string path = directory + "/" + city; // TODO replace

            if (opendir (path.c_str()) != nullptr) {
                std::string nodesFile = path + "/" + "nodes.txt"; // TODO use const
                std::string edgesFile = path + "/" + "edges.txt"; // TODO use const

                long old = graph.nodesAmount();
                this->graph.append(nodesFile, edgesFile, city);
                cout << "Read " << graph.nodesAmount() - old << " nodes from " << city << "." << endl;
            } else {
                cerr << path << endl;
                throw InvalidDirectoryException(path);
            }
        }

        // TODO read country

        closedir(dir);
    } else {
        cerr << directory << endl;
        throw InvalidDirectoryException(directory);
    }
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
