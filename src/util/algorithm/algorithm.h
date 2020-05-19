#ifndef FEUP_CAL_PROJ_ALGORITHM_H
#define FEUP_CAL_PROJ_ALGORITHM_H

#include <list>
#include <tuple>
#include <queue>
#include "trio.h"
#include "../graph/graph.h"
#include "../graph/cluster.h"

/**
 * @brief Contains useful and required graph-related algorithms
 */
namespace algorithm {
    /**
     * @brief Calculates clusters of vertexes in a graph of locations.
     *
     * @param graph         the graph
     * @param clusterAmount the number of clusters to calculate
     * @param iterations    the number of iterations to run
     * @return              the vector of formed clusters
     */
    std::vector<Cluster> kMeans(const Graph<Location> &graph, int clusterAmount, int iterations);

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
    Trio<T> getPath(Graph<T> &simplifiedGraph, const T &source,
                    const T &destination);

    /**
     * @brief Gets the reduced graph from a given graph
     *
     * @param graph	    graph to be reduced
     * @param vector	vertexes of the reduced graph
     * @return			the reduced graph
     */
    template <class T>
    Graph<T> graph_reduction(Graph<T> graph, const std::vector<Location>& locations);

    template<class T>
    void dijkstra(Graph<T> &gra, const Vertex<T> &sourceVertex);
};

#include "algorithm.tpp"

#endif //FEUP_CAL_PROJ_ALGORITHM_H
