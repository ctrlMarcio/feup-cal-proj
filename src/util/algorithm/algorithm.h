#ifndef FEUP_CAL_PROJ_ALGORITHM_H
#define FEUP_CAL_PROJ_ALGORITHM_H

#include <list>
#include <tuple>
#include <queue>
#include "../graph/graph.h"
#include "../graph/cluster.h"

/**
 * @brief Contains useful and required graph-related algorithms
 */
namespace algorithm {
    std::vector<std::vector<double>> floydWarshallMatrix(const Graph<Location> &graph);

    std::vector<Cluster> kMeans(const Graph<Location> &graph, int clusterAmount, int iterations);

    template <class T>
    std::list<Vertex<T>> getPath(const Graph<T> &simplifiedGraph, const T &sourceNode, const T &destinationNode);
};


#endif //FEUP_CAL_PROJ_ALGORITHM_H
