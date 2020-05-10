#include <gtest/gtest.h>
#include <util/graph/graph.h>

using testing::Eq;

TEST(graph, add_vertex_test) {
	Graph<Location> graph;

	Location a(20, "", 0,0);
	bool add = graph.addVertex(a);

	EXPECT_EQ((*graph.getVertexSet().begin()).pointer->getInfo(), Location(20, "ads", 0, 0));
	EXPECT_TRUE(add);

	graph.addVertex(a);

	EXPECT_EQ(graph.getVertexSet().size(), 1);
}

TEST(graph, add_edge_test) {
	Graph<Location> graph;

    Location a(1, "", 0, 0);
    Location b(2, "", 0, 0);

	auto e1 = graph.addEdge(a, b, 20);
	EXPECT_EQ(e1, nullptr);

	bool v1 = graph.addVertex(a);
	auto e2 = graph.addEdge(a, b, 20);
	EXPECT_EQ(e2, nullptr);
	EXPECT_TRUE(v1);
}