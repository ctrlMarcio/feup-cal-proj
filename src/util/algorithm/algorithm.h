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
     * @param locations         the locations that are required for the complete path
     * @param path              the hypothetical path
     * @return                  true, if the path is complete. false, otherwise
     */
    bool isComplete(const std::vector<Location> &locations, const std::list<Vertex<Location>> &path);

    /**
     * @brief Gets the paths for a graph, a garage, a headquarters location and a group of clusters.
     *
     * @param simplifiedGraph   the graph
     * @param source            the source location
     * @param destination       the destination location
     * @param clusters          the clusters that contain the required locations
     * @return                  the path
     */
    std::list<Path<Location>> pathFinder(Graph<Location> &graph, const Location &source, const Location &destination,
                                         const std::vector<Cluster> &clusters);

    /**
     * @brief Finds the paths for a given company client.
     *
     * @param companyClient     the company client
     * @param company           the company
     * @return                  the optimal paths
     */
    std::pair<std::list<Path<Location>>, std::vector<Cluster>>
    getPaths(const CompanyClient &companyClient, Company &company);

    /**
     * @brief Gets the reduced graph from a given graph.
     *
     * @param graph	    graph to be reduced
     * @param vector	locations of the reduced graph
     * @return			the reduced graph
     */
    template<class T>
    Graph<T> reduceGraph(Graph<T> graph, const std::vector<Location> &locations);

    /**
     * @brief Calculates the minimal distance between a vertex and all the others.
     *
     * @tparam T            the content of the vertex
     * @param gra           the graph
     * @param sourceVertex  the source vertex
     */
    template<class T>
    void dijkstra(Graph<T> &gra, const Vertex<T> &sourceVertex);

    /**
     * @brief Verifies if a list has cycles in it.
     *
     * @tparam T            the content of the list
     * @param list          the list
     * @param lastElements  the number of elements to verify
     * @return              true, if the list has cycles in it. false, otherwise
     */
    template<class T>
    bool hasCycle(std::list<T> list, int lastElements = 10);

    /**
     * @brief Verifies if the last elements of a list have a reversion.
     * Won't apply if the vertex that reverts has only one outgoing edge.
     * For example, 1,2,3,2,1 has a reversion.
     *
     * @tparam T        the content of the vertices
     * @param vertices  the vertices
     * @return          true, if the list reverts. false, otherwise
     */
    template<class T>
    bool reverts(std::list<Vertex<T>> vertices);
};

#include "algorithm.tpp"

#endif //FEUP_CAL_PROJ_ALGORITHM_H
