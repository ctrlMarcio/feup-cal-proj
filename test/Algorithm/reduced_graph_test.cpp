#include <gtest/gtest.h>
#include <model/company_client/company_client.h>
#include <util/graph/graph.h>
#include <util/algorithm/algorithm.h>

using testing::Eq;

template<class T>
Graph<Location> createGraph()
{
    Graph<T> simplified_graph;
    Location l1(1, "a", 1, 1);
    Location l2(2, "b", 2, 2);
    Location l3(3, "c", 3, 3);
    Location l4(4, "d", 4, 4);
    simplified_graph.add(l1);
    simplified_graph.add(l2);
    simplified_graph.add(l3);
    simplified_graph.add(l4);
    simplified_graph.add(l1,l2,1);
    simplified_graph.add(l2,l3,1);
    simplified_graph.add(l1,l4,1);
    simplified_graph.add(l4,l3,2);

    return simplified_graph;
}


TEST(reduced_graph, algorithm_reduced) {
    Graph<Location> graph = createGraph<Location>();

    Location l1(1, "a", 1, 1);
    Location l3(3, "c", 3, 3);

    std::vector<Location> vector;
    vector.push_back(l1);
    vector.push_back(l3);

    Graph<Location> simpleGraph = algorithm::graph_reduction<Location>(graph, vector);

    EXPECT_EQ(simpleGraph.getVertex(l1).weightTo(&simpleGraph.getVertex(l3)), 2);
    EXPECT_EQ(simpleGraph.getVertex(l3).weightTo(&simpleGraph.getVertex(l1)), INF);
}
