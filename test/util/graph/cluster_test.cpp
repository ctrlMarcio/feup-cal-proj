#include <gtest/gtest.h>
#include <util/graph/cluster.h>

using testing::Eq;

bool addVertex(Cluster &cluster, Vertex<Location> *vertex) {
    PointerWrapper<Vertex<Location>> ptr(vertex);
    return cluster.addVertex(ptr);
}

TEST(cluster, update_centroid_test) {
    Cluster cluster;

    std::pair<double, double> centroid = cluster.updateCentroid();
    std::pair<double, double> res(-1, -1);

    EXPECT_NEAR(centroid.first, res.first, 0.0001);
    EXPECT_NEAR(centroid.second, res.second, 0.0001);

    Location location(1, "", 10, 10);
    Vertex<Location> vertex(location);
    addVertex(cluster, &vertex);

    centroid = cluster.updateCentroid();
    res = std::pair<double, double>(10, 10);
    EXPECT_NEAR(centroid.first, res.first, 0.0001);
    EXPECT_NEAR(centroid.second, res.second, 0.0001);
    EXPECT_NEAR(centroid.first, cluster.getCentroid().first, 0.0001);
    EXPECT_NEAR(centroid.second, cluster.getCentroid().second, 0.0001);
}

TEST(cluster, add_vertex_test) {
    Cluster cluster;

    Location l1(1, "", 5, 5);
    Vertex<Location> vertex(l1);
    bool added = addVertex(cluster, &vertex);

    ASSERT_TRUE(added);
    ASSERT_EQ(cluster.getVertexes().size(), 1);

    Location l2(1, "", 5, 5);
    vertex = Vertex<Location>(l2);
    added = addVertex(cluster, &vertex);

    ASSERT_FALSE(added);
    ASSERT_EQ(cluster.getVertexes().size(), 1);

    Location l3(2, "", 10, 10);
    vertex = Vertex<Location>(l3);
    added = addVertex(cluster, &vertex);

    ASSERT_TRUE(added);
    ASSERT_EQ(cluster.getVertexes().size(), 2);
}

TEST(cluster, clear_test) {
    Cluster cluster;

    Location l1(1, "", 5, 5);
    Location l2(2, "", 10, 10);

    Vertex<Location> v1(l1);
    Vertex<Location> v2(l2);

    addVertex(cluster, &v1);
    addVertex(cluster, &v2);

    ASSERT_FALSE(cluster.getVertexes().empty());

    cluster.clear();

    ASSERT_TRUE(cluster.getVertexes().empty());

    cluster.clear();

    ASSERT_TRUE(cluster.getVertexes().empty());
}