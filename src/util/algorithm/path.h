#ifndef FEUP_CAL_PROJ_PATH_H
#define FEUP_CAL_PROJ_PATH_H

#include <list>
#include "../graph/vertex.h"
#include "../graph/cluster.h"

template<typename T>
class Path {
public:
    Path(const std::list<Vertex<T>> &path, double pathCost, Cluster &cluster);

    const list<Vertex<T>> &getPath() const;

    double getPathCost();

    Cluster &getCluster();

private:
    Cluster cluster;

    std::list<Vertex<T>> path;

    double pathCost;
};

#include "path.tpp"

#endif //FEUP_CAL_PROJ_PATH_H
