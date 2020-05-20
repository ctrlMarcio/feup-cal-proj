#include "cluster.h"

std::pair<double, double> Cluster::updateCentroid() {
    if (this->locations.empty()) {
        this->centroid = std::pair<double, double>(-1, -1);
        return this->centroid;
    }

    double xAvg = 0, yAvg = 0;

    for (auto &l : locations) {
        xAvg += l.getX();
        yAvg += l.getY();
    }

    xAvg /= this->locations.size();
    yAvg /= this->locations.size();

    this->centroid = std::pair<double, double>(xAvg, yAvg);
    return this->centroid;
}

bool Cluster::add(const Location &location) {
    return this->locations.insert(location).second;
}

void Cluster::clear() {
    this->locations.clear();
}

const pair<double, double> &Cluster::getCentroid() const {
    return centroid;
}

const unordered_set<Location, location_hash> &Cluster::getLocations() const {
    return locations;
}
