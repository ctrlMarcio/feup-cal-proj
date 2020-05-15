#include "cluster.h"

std::pair<double, double> Cluster::updateCentroid() {
    if (this->vertexes.empty()) {
        this->centroid = std::pair<double, double>(-1 , -1);
        return this->centroid;
    }

    double xAvg = 0, yAvg = 0;

    for (auto ptr : vertexes) {
        xAvg += ptr.getPointer()->getInfo().getX();
        yAvg += ptr.getPointer()->getInfo().getY();
    }

    xAvg /= this->vertexes.size();
    yAvg /= this->vertexes.size();

    this->centroid = std::pair<double, double>(xAvg, yAvg);
    return this->centroid;
}

bool Cluster::addVertex(const PointerWrapper<Vertex<Location>> &vertex) {
    return this->vertexes.insert(vertex).second;
}

void Cluster::clearCluster() {
    this->vertexes.clear();
}

const pair<double, double> &Cluster::getCentroid() const {
    return centroid;
}
