#include <gtest/gtest.h>
#include <util/graph/edge.h>
#include <util/graph/vertex.h>

using testing::Eq;

TEST(edge, constructor_test) {
    auto dest = new Vertex<char>('a');
    auto notDest = new Vertex<char>('b');
    Edge<char> e(notDest, dest, 20);

    EXPECT_EQ(e.getDestination(), dest);
    EXPECT_EQ(e.getWeight(), 20);
    EXPECT_NE(e.getDestination(), notDest);
    EXPECT_NE(e.getWeight(), -20);
}