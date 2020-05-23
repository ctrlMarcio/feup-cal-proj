#include <gtest/gtest.h>
#include <model/location/location.h>
#include <util/graph/graph.h>
#include <util/graph/cluster.h>
#include <util/algorithm/algorithm.h>

using testing::Eq;

TEST(algorithm, k_means_test1) {
    Location l1(1, "", 0, 0);
    Location l2(2, "", 10, 10);
    Location l3(3, "", 20, 20);

    std::vector<Location> locations;

    locations.push_back(l1);
    locations.push_back(l2);
    locations.push_back(l3);

    std::vector<Cluster> clusters = algorithm::kMeans(locations, 3, 1);

    EXPECT_EQ(clusters.size(), 3);
    for (const auto &cluster : clusters)
        EXPECT_FALSE(cluster.getLocations().empty());
}

TEST(algorithm, k_means_test2) {
    std::vector<Location> locations;

    Location l1(1, "", 0, 0);
    Location l2(2, "", 10, 10);
    Location l3(3, "", 20, 20);
    Location l4(4, "", 1, 1);
    Location l5(5, "", 11, 11);
    Location l6(6, "", 21, 21);

    locations.push_back(l1);
    locations.push_back(l2);
    locations.push_back(l3);
    locations.push_back(l4);
    locations.push_back(l5);
    locations.push_back(l6);

    std::vector<Cluster> clusters = algorithm::kMeans(locations, 3);

    EXPECT_EQ(clusters.size(), 3);
    for (const auto &cluster : clusters)
        EXPECT_EQ(cluster.getLocations().size(), 2);
}

TEST(algorithm, k_means_test3) {
    std::vector<Location> locations;

    Location l1(1, "", 0, 0);
    Location l2(2, "", 10, 10);
    Location l3(3, "", 20, 20);
    Location l4(4, "", 2, 2);
    Location l5(5, "", 11, 11);
    Location l6(6, "", 3, 3);

    locations.push_back(l1);
    locations.push_back(l2);
    locations.push_back(l3);
    locations.push_back(l4);
    locations.push_back(l5);
    locations.push_back(l6);

    std::vector<Cluster> clusters = algorithm::kMeans(locations, 3);

    EXPECT_EQ(clusters.size(), 3);
    EXPECT_EQ(clusters[0].getLocations().size(), 3);
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

    Cluster cluster;
    cluster.add(g);
    cluster.add(v1);
    cluster.add(v2);
    cluster.add(v3);
    cluster.add(v4);
    cluster.add(v5);
    cluster.add(v6);
    cluster.add(h);
    std::vector<Cluster> vector;
    vector.push_back(cluster);

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

    std::list<Path<Location>> list = algorithm::pathFinder(graph, g, h, vector);
    Path<Location> path = *list.begin();

    std::list<Vertex<Location>> expectedPath;

    expectedPath.push_back(graph.getVertex(g));
    expectedPath.push_back(graph.getVertex(v1));
    expectedPath.push_back(graph.getVertex(v2));
    expectedPath.push_back(graph.getVertex(v6));
    expectedPath.push_back(graph.getVertex(v4));
    expectedPath.push_back(graph.getVertex(v3));
    expectedPath.push_back(graph.getVertex(v5));
    expectedPath.push_back(graph.getVertex(h));

    EXPECT_EQ(path.getPath().size(), 8);
    EXPECT_EQ(path.getPathCost(), 14);
    EXPECT_EQ(path.getPath(), expectedPath);
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

    Cluster cluster;
    cluster.add(g);
    cluster.add(v1);
    cluster.add(v2);
    cluster.add(v3);
    cluster.add(v4);
    cluster.add(v5);
    cluster.add(v6);
    cluster.add(h);
    std::vector<Cluster> vector;
    vector.push_back(cluster);

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

    std::list<Path<Location>> list = algorithm::pathFinder(graph, g, h, vector);
    Path<Location> path = *list.begin();

    std::list<Vertex<Location>> expectedPath;

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

    EXPECT_EQ(path.getPath().size(), 10);
    EXPECT_EQ(path.getPathCost(), 18);
    EXPECT_EQ(path.getPath(), expectedPath);
}

TEST(algorithm, paths_finder) {
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

    Company company("lolbro", g, graph, 1);

    CompanyClient companyClient("LOLBRO", CompanyRepresentative("", ""), h);

    companyClient.addPickupPoint(v1);
    companyClient.addPickupPoint(v2);
    companyClient.addPickupPoint(v3);
    companyClient.addPickupPoint(v4);
    companyClient.addPickupPoint(v5);
    companyClient.addPickupPoint(v6);

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

    std::pair<std::list<Path<Location>>, std::vector<Cluster>> paths = algorithm::getPaths(companyClient, company);

    EXPECT_EQ(paths.first.size(), 1);
}

TEST(algorithm, paths_finder2) {
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

    Company company("lolbro", g, graph, 2);

    CompanyClient companyClient("LOLBRO", CompanyRepresentative("", ""), h);

    companyClient.setVehicleNumber(2);

    companyClient.addPickupPoint(v1);
    companyClient.addPickupPoint(v2);
    companyClient.addPickupPoint(v3);
    companyClient.addPickupPoint(v4);
    companyClient.addPickupPoint(v5);
    companyClient.addPickupPoint(v6);

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

    std::pair<std::list<Path<Location>>, std::vector<Cluster>> paths = algorithm::getPaths(companyClient, company);

    EXPECT_EQ(paths.first.size(), 2);
}

TEST(algorithm, paths_finder3) {
    Graph<Location> graph;

    Location g(0, "None", 0, 0);

    Location v1(1, "None", 0, 100);
    Location v2(2, "None", 10, 100);

    Location v3(3, "None", 100, 0);
    Location v4(4, "None", 100, 10);

    Location h(5, "None", 100, 100);

    graph.add(g);
    graph.add(v1);
    graph.add(v2);
    graph.add(v3);
    graph.add(v4);
    graph.add(h);

    graph.add(g, v1, 90);
    graph.add(v1, v2, 1);
    graph.add(v2, v1, 2);
    graph.add(v1, v3, 120);
    graph.add(v2, h, 90);
    graph.add(v3, v4, 5);
    graph.add(v4, h, 80);

    Company company("lolbro", g, graph, 2);

    CompanyClient companyClient("LOLBRO", CompanyRepresentative("", ""), h);

    companyClient.setVehicleNumber(2);

    companyClient.addPickupPoint(v1);
    companyClient.addPickupPoint(v2);
    companyClient.addPickupPoint(v3);
    companyClient.addPickupPoint(v4);

    std::pair<std::list<Path<Location>>, std::vector<Cluster>> paths = algorithm::getPaths(companyClient, company);

    EXPECT_EQ(paths.first.size(), 2);
}

TEST(algorithm, cycles_test) {
    std::list<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(2);

    EXPECT_TRUE(algorithm::hasCycle(list));

    list.push_back(3);

    EXPECT_FALSE(algorithm::hasCycle(list));

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(2);

    EXPECT_TRUE(algorithm::hasCycle(list));
}