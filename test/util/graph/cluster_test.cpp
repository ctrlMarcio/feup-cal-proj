#include <gtest/gtest.h>
#include <util/graph/cluster.h>

using testing::Eq;

TEST(cluster, update_centroid_test) {
    Cluster cluster;

    std::pair<double, double> centroid = cluster.updateCentroid();
    std::pair<double, double> res(-1, -1);

    EXPECT_NEAR(centroid.first, res.first, 0.0001);
    EXPECT_NEAR(centroid.second, res.second, 0.0001);

    Location location(1, "", 10, 10);
    cluster.add(location);

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
    bool added = cluster.add(l1);

    ASSERT_TRUE(added);
    ASSERT_EQ(cluster.getLocations().size(), 1);

    Location l2(1, "", 5, 5);
    added = cluster.add(l2);

    ASSERT_FALSE(added);
    ASSERT_EQ(cluster.getLocations().size(), 1);

    Location l3(2, "", 10, 10);
    added = cluster.add(l3);

    ASSERT_TRUE(added);
    ASSERT_EQ(cluster.getLocations().size(), 2);
}

TEST(cluster, clear_test) {
    Cluster cluster;

    Location l1(1, "", 5, 5);
    Location l2(2, "", 10, 10);


    cluster.add(l1);
    cluster.add(l2);

    ASSERT_FALSE(cluster.getLocations().empty());

    cluster.clear();

    ASSERT_TRUE(cluster.getLocations().empty());

    cluster.clear();

    ASSERT_TRUE(cluster.getLocations().empty());
}