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

    graph.add(l1);
    graph.add(l2);
    graph.add(l3);

    std::vector<Cluster> clusters = algorithm::kMeans(graph, 3, 1);

    EXPECT_EQ(clusters.size(), 3);
    for (const auto &cluster : clusters)
        EXPECT_FALSE(cluster.getVertexes().empty());
}

TEST(algorithm, pathfinder_test) {
    Graph<Location> graph;

    Location g(1, "None", 0, 0);
    Location v1(2, "None", 10, 10);
    Location v2(3, "None", 20, 0);
    Location v3(4, "None", -10, -10);
    Location v4(5, "None", 10, -10);
    Location v5(6, "None", 0, -20);
    Location v6(7, "None", 20, 20);
    Location h(8, "None", 10, 25);

    graph.add(g);
    graph.add(v1);
    graph.add(v2);
    graph.add(v3);
    graph.add(v4);
    graph.add(v5);
    graph.add(v6);
    graph.add(h);

    graph.add(g, v1, 1);
    graph.add(g, v2, 3);
    graph.add(g, v3, 4);
    graph.add(g, v4, 3);

    graph.add(v1, v2, 2);

    graph.add(v2, v1, 2);
    graph.add(v2, v6, 3);

    graph.add(v3, g, 3);
    graph.add(v3, v5, 2);

    graph.add(v4, v3, 1);
    graph.add(v4, v5, 3);
    graph.add(v4, v6, 3);

    graph.add(v5, v4, 3);
    graph.add(v5, h, 3);

    graph.add(v6, v4, 2);
    graph.add(v6, h, 3);

    graph.add(h, v5, 2);

    Trio<Location> trio = algorithm::getPath(graph, g, h);

    list<Vertex<Location>> expectedPath;

    expectedPath.push_back(graph.getVertex(g));
    expectedPath.push_back(graph.getVertex(v1));
    expectedPath.push_back(graph.getVertex(v2));
    expectedPath.push_back(graph.getVertex(v6));
    expectedPath.push_back(graph.getVertex(v4));
    expectedPath.push_back(graph.getVertex(v3));
    expectedPath.push_back(graph.getVertex(v5));
    expectedPath.push_back(graph.getVertex(h));

    EXPECT_EQ(trio.getPath().size(), 8);
    EXPECT_EQ(trio.getPathCost(), 14);
    EXPECT_EQ(trio.getPath(), expectedPath);
}

TEST(algorithm, pathfinder_test2) {
    Graph<Location> graph;

    Location g(1, "None", 0, 0);
    Location v1(2, "None", 10, 10);
    Location v2(3, "None", 20, 0);
    Location v3(4, "None", -10, -10);
    Location v4(5, "None", 10, -10);
    Location v5(6, "None", 0, -20);
    Location v6(7, "None", 20, 20);
    Location h(8, "None", 10, 25);

    graph.add(g);
    graph.add(v1);
    graph.add(v2);
    graph.add(v3);
    graph.add(v4);
    graph.add(v5);
    graph.add(v6);
    graph.add(h);

    graph.add(g, v1, 1);
    graph.add(g, v2, 3);
    graph.add(g, v3, 4);
    graph.add(g, v4, 3);

    graph.add(v1, v2, 2);

    graph.add(v2, v1, 2);
    graph.add(v2, v6, 3);

    graph.add(v3, g, 3);
    graph.add(v3, v5, 2);

    graph.add(v4, v3, 1);
    graph.add(v4, v5, 3);
    graph.add(v4, v6, 3);

    graph.add(v5, v4, 3);
    graph.add(v5, h, 3);

    graph.add(v6, v4, 7);
    graph.add(v6, h, 1);

    graph.add(h, v5, 2);

    Trio<Location> trio = algorithm::getPath(graph, g, h);

    list<Vertex<Location>> expectedPath;

    expectedPath.push_back(graph.getVertex(g));
    expectedPath.push_back(graph.getVertex(v1));
    expectedPath.push_back(graph.getVertex(v2));
    expectedPath.push_back(graph.getVertex(v6));
    expectedPath.push_back(graph.getVertex(h));
    expectedPath.push_back(graph.getVertex(v5));
    expectedPath.push_back(graph.getVertex(v4));
    expectedPath.push_back(graph.getVertex(v3));
    expectedPath.push_back(graph.getVertex(v5));
    expectedPath.push_back(graph.getVertex(h));

    EXPECT_EQ(trio.getPath().size(), 10);
    EXPECT_EQ(trio.getPathCost(), 18);
    EXPECT_EQ(trio.getPath(), expectedPath);
}