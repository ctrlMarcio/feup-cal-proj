#ifndef FEUP_CAL_PROJ_REDUCED_GRAPH_TEST_H
#define FEUP_CAL_PROJ_REDUCED_GRAPH_TEST_H

#include "../graph/graph.h"

/**
 * @brief Gets the reduced graph from a given graph
 *
 * @param graph	    graph to be reduced
 * @param vector	vertexes of the reduced graph
 * @return			the reduced graph
 */
template <class T>
Graph<T> graph_reduction(Graph<T> graph, const std::vector<Location> locations)
{
    Graph<T> simplified_graph;

    for (auto i: locations)
        simplified_graph.add(i);

    for (auto source: locations)
    {
        graph.dijkstra(source);
        for (auto dest: locations)
        {
            if (source!=dest)
            {
                simplified_graph.getVertex(source).add(&simplified_graph.getVertex(dest),graph.getVertex(dest).dist);
            }
        }
    }
    return simplified_graph;
};

#endif //FEUP_CAL_PROJ_REDUCED_GRAPH_TEST_H
