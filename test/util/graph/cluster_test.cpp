#include <gtest/gtest.h>
#include <util/graph/cluster.h>

using testing::Eq;

bool addVertex(Cluster &cluster, const Location &location) {
    Vertex<Location> vertex(location);
    PointerWrapper<Vertex<Location>> ptr(&vertex);
    return cluster.addVertex(ptr);
}

TEST(cluster, update_centroid_test) {
    Cluster cluster;

    std::pair<double, double> centroid = cluster.updateCentroid();
    std::pair<double, double> res(-1, -1);

    EXPECT_EQ(centroid, res);

    Location location(1, "", 10, 10);
    addVertex(cluster, location);

    centroid = cluster.updateCentroid();
    res = std::pair<double, double>(10, 10);
    EXPECT_NEAR(centroid.first, res.first, 0.0001);
    EXPECT_NEAR(centroid.second, res.second, 0.0001);
    EXPECT_EQ(centroid, cluster.getCentroid());
}

TEST(cluster, add_vertex_test) {
    Cluster cluster;

    Location l1(1, "", 5, 5);
    bool added = addVertex(cluster, l1);

    ASSERT_TRUE(added);
    ASSERT_EQ(cluster.getVertexes().size(), 1);

    Location l2(1, "", 5, 5);
    added = addVertex(cluster, l2);

    ASSERT_FALSE(added);
    ASSERT_EQ(cluster.getVertexes().size(), 1);

    Location l3(2, "", 10, 10);
    added = addVertex(cluster, l3);

    ASSERT_TRUE(added);
    ASSERT_EQ(cluster.getVertexes().size(), 2);
}

TEST(cluster, clear_test) {
    Cluster cluster;

    Location l1(1, "", 5, 5);
    Location l2(2, "", 10, 10);

    addVertex(cluster, l1);
    addVertex(cluster, l2);

    ASSERT_FALSE(cluster.getVertexes().empty());

    cluster.clear();

    ASSERT_TRUE(cluster.getVertexes().empty());

    cluster.clear();

    ASSERT_TRUE(cluster.getVertexes().empty());
}