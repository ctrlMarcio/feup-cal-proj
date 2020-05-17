#include <gtest/gtest.h>
#include <model/location/location.h>
#include <util/graph/graph.h>
#include <util/graph/cluster.h>
#include <util/algorithm/algorithm.h>

using testing::Eq;

TEST(algorithm, k_means_test) {
        Graph<Location> graph;

        Location l1(1, "", 0, 0);
        Location l2(2, "", 10, 10);
        Location l3(3, "", 20, 20);

        graph.addVertex(l1);
        graph.addVertex(l2);
        graph.addVertex(l3);

        std::vector<Cluster> clusters = algorithm::kMeans(graph, 3, 1);

        EXPECT_EQ(clusters.size(), 3);
        for (const auto &cluster : clusters)
            EXPECT_FALSE(cluster.getVertexes().empty());
}