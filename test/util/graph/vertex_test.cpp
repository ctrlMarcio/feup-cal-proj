#include <gtest/gtest.h>
#include <util/graph/vertex.h>

using testing::Eq;

TEST(vertex, simple_construction_test) {
    Vertex<int> vertex(1);

    EXPECT_EQ(vertex.get(), 1);
    EXPECT_NE(vertex.get(), 2);
}

TEST(vertex, add_edge_test) {
    Vertex<string> vertex("a");
    auto dest = new Vertex<string>("aa");

    vertex.add(dest, -1);

    EXPECT_EQ(vertex.getOutgoing()[0]->getDestination(), dest);
}