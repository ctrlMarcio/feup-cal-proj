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

    struct my_comparator
    {
        template<typename T>
        int operator() (const Trio<T>& p1, const Trio<T>& p2)
        {
            return p1 > p2;
        }
    };

    template<class T>
    bool isComplete(Graph<T> &simplifiedGraph, const std::list<Vertex<T>> &path) {
        bool complete = true;

        for (const auto &elem : simplifiedGraph.getVertices())
            if (find(path.begin(), path.end(), elem) == path.end()) return false;

        return complete;
    }

    template<class T>
    Trio<T> getPath(Graph<T> &simplifiedGraph, const T &source,
                            const T &destination) {
        std::priority_queue<Trio<T>, std::vector<Trio<T>>, my_comparator> queue;

        const Vertex<T> &sourceVertex = simplifiedGraph.getVertex(source);
        const Vertex<T> &destinationVertex = simplifiedGraph.getVertex(destination);

        Trio<T> current(sourceVertex);

        queue.push(current);

        while (!(current.getVertex() == destinationVertex && isComplete(simplifiedGraph, current.getPath()))) {
            Trio<T> min = queue.top();
            queue.pop();

            for (const std::shared_ptr<Edge<T>> &child : min.getVertex().getOutgoing())
                queue.push(Trio<T>(min, *child));

            current = min;
        }

        return current;
    }

};


#endif //FEUP_CAL_PROJ_ALGORITHM_H
