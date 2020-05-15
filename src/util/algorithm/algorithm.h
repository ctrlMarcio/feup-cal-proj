#ifndef FEUP_CAL_PROJ_ALGORITHM_H
#define FEUP_CAL_PROJ_ALGORITHM_H

#include "../graph/graph.h"
#include "../graph/cluster.h"

/**
 * @brief Contains useful and required graph-related algorithms
 */
namespace algorithm {
    std::vector<std::vector<double>> floydWarshallMatrix(const Graph<Location> &graph);

    std::vector<Cluster> kMeans(const Graph<Location> &graph, int clusterAmount, int iterations);
};


#endif //FEUP_CAL_PROJ_ALGORITHM_H
