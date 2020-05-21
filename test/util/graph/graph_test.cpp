#include <gtest/gtest.h>
#include <util/graph/graph.h>

using testing::Eq;

TEST(graph, add_vertex_test) {
    Graph<Location> graph;

    Location a(20, "", 0, 0);
    graph.add(a);

    EXPECT_EQ(graph.getVertices()[0].get(), Location(20, "", 0, 0));

    //graph.add(a);

    //EXPECT_EQ(graph.getVertices().size(), 1);
}

TEST(graph, add_edge_test) {
    Graph<Location> graph;

    Location a(1, "", 0, 0);
    Location b(2, "", 0, 0);

    EXPECT_THROW(graph.add(a, b, 20), InvalidVertexException);

    EXPECT_THROW(graph.add(a, b, 20), InvalidVertexException);
}