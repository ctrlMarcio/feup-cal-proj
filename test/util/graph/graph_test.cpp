#include <gtest/gtest.h>
#include <util/graph/graph.h>

using testing::Eq;

TEST(graph, add_vertex_test) {
	Graph<int> graph;

	auto vertex = graph.addVertex(20);

	EXPECT_EQ(graph.getVertexSet()[0]->getInfo(), 20);
	EXPECT_EQ(graph.getVertexSet()[0], vertex);

	graph.addVertex(20);

	EXPECT_EQ(graph.getVertexSet().size(), 1);
}

TEST(graph, add_edge_test) {
	Graph<int> graph;

	auto e1 = graph.addEdge(1, 2, 20);
	EXPECT_EQ(e1, nullptr);

	graph.addVertex(1);
	auto e2 = graph.addEdge(1, 2, 20);
	EXPECT_EQ(e2, nullptr);

	graph.addVertex(2);
	auto e3 = graph.addEdge(1, 2, 20);
	EXPECT_EQ(graph.getVertexSet()[0]->getAdj().size(), 1);
}