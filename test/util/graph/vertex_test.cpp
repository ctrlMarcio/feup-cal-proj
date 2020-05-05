#include <gtest/gtest.h>
#include <util/graph/vertex.h>

using testing::Eq;

TEST(vertex, simple_construction_test) {
	Vertex<int> vertex(1);

	EXPECT_EQ(vertex.getInfo(), 1);
	EXPECT_NE(vertex.getInfo(), 2);
}

TEST(vertex, add_edge_test) {
	Vertex<string> vertex("a");
	auto dest = make_shared<Vertex<string>>("aa");

	auto edge = vertex.addEdge(dest, -1);

	EXPECT_EQ(vertex.getAdj()[0]->getDest(), dest);
}