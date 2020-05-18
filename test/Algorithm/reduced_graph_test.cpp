#include <gtest/gtest.h>
#include <model/company_client/company_client.h>
#include <util/graph/graph.h>
#include <util/algorithm/reduced_graph.h>

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
    std::vector<Location> vetor;
    Location l1(1, "a", 1, 1);
    Location l3(3, "c", 3, 3);
    vetor.push_back(l1);
    vetor.push_back(l3);
    //Graph<Location> simplified_graph2 = graph_reduction<Location>(graph,vetor);
    graph.dijkstra(l1);
    cout << graph.getVertex(l3).dist;

    //EXPECT_EQ(simplified_graph2.getVertex(l1).weightTo(&simplified_graph2.getVertex(l3)), 2);

}
