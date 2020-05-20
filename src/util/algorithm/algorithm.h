#ifndef FEUP_CAL_PROJ_ALGORITHM_H
#define FEUP_CAL_PROJ_ALGORITHM_H

#include <list>
#include <tuple>
#include <queue>
#include "trio.h"
#include "path.h"
#include "../graph/mutable_priority_queue.h"
#include "../graph/graph.h"
#include "../graph/cluster.h"
#include "../../model/company_client/company_client.h"
#include "../../model/company/company.h"

/**
 * @brief Contains useful and required graph-related algorithms
 */
namespace algorithm {
    /**
     * @brief Calculates clusters of locations in a vector of locations.
     *
     * @param locations     the locations
     * @param clusterAmount the number of clusters to calculate
     * @param iterations    the number of iterations to run, with 10 as default
     * @return              the vector of formed clusters
     */
    std::vector<Cluster> kMeans(const std::vector<Location> &locations, int clusterAmount, int iterations = 10);

    /**
     * @brief  Verifies if the path is complete.
     *
     * @tparam T                the type of the vertices
     * @param simplifiedGraph   the simplified graph
     * @param path              the hypothetical path
     * @return                  true, if the path is complete. false, otherwise
     */
    template<class T>
    bool isComplete(Graph<T> &simplifiedGraph, const std::list<Vertex<T>> &path);

    /**
     * @brief Gets the path for a simplified graph, a garage and an headquarters location.
     *
     * @tparam T                the type of the vertices
     * @param simplifiedGraph   the simplified graph
     * @param source            the source vertex
     * @param destination       the destination vertex
     * @return                  the path
     */
    template<class T>
    Path<T> getPath(Graph<T> &simplifiedGraph, const T &source,
                    const T &destination);

    /**
     * @brief Gets the reduced graph from a given graph
     *
     * @param graph	    graph to be reduced
     * @param vector	locations of the reduced graph
     * @return			the reduced graph
     */
    template<class T>
    Graph<T> reduceGraph(Graph<T> graph, const std::vector<Location> &locations);

    template<class T>
    void dijkstra(Graph<T> &gra, const Vertex<T> &sourceVertex);

    std::list<Path<Location>>
    getPaths(const Graph<Location> worldGraph, const CompanyClient &companyClient, const Company &company);
};

#include "algorithm.tpp"

#endif //FEUP_CAL_PROJ_ALGORITHM_H
