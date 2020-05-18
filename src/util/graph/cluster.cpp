#include "cluster.h"

std::pair<double, double> Cluster::updateCentroid() {
    if (this->vertexes.empty()) {
        this->centroid = std::pair<double, double>(-1 , -1);
        return this->centroid;
    }

    double xAvg = 0, yAvg = 0;

    for (auto &v : vertexes) {
        xAvg += v.get().getX();
        yAvg += v.get().getY();
    }

    xAvg /= this->vertexes.size();
    yAvg /= this->vertexes.size();

    this->centroid = std::pair<double, double>(xAvg, yAvg);
    return this->centroid;
}

bool Cluster::addVertex(const Vertex<Location> &vertex) {
    return this->vertexes.insert(vertex).second;
}

void Cluster::clear() {
    this->vertexes.clear();
}

const pair<double, double> &Cluster::getCentroid() const {
    return centroid;
}

const unordered_set<Vertex<Location>, vertex_hash> &Cluster::getVertexes() const {
    return vertexes;
}
