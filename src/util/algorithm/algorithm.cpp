#include "algorithm.h"
#include <algorithm>

std::vector<Cluster> algorithm::kMeans(const std::vector<Location> &locations, int vehicleCount, int iterations) {
    // initialize clusters
    std::vector<Cluster> clusters;
    if (vehicleCount <= 0 || iterations <= 0 || locations.empty())
        return clusters;

    int clusterAmount = std::min(vehicleCount, (int) locations.size());

    unsigned long increment = locations.size() / clusterAmount;
    if (!increment)
        increment = 1;

    auto iterator = locations.begin();
    int i = 0;
    for (; i < clusterAmount; ++i) {
        Cluster cluster;
        cluster.add(*iterator);
        clusters.push_back(cluster);

        iterator = std::next(iterator, increment);
    }

    for (; i < vehicleCount; ++i)
        clusters.emplace_back();

    for (int j = 0; j < iterations; ++j) {
        // compute centroids and clear the clusters
        for (Cluster &cluster : clusters) {
            cluster.updateCentroid();
            cluster.clear();
        }

        // assign point to nearest cluster
        for (const Location &l : locations) {
            double min = INF;
            Cluster *chosen = &clusters[0];

            for (Cluster &cluster : clusters) {
                double distance = l.euclideanDistanceTo(cluster.getCentroid().first,
                                                        cluster.getCentroid().second);
                if (distance < min) {
                    min = distance;
                    chosen = &cluster;
                }
            }

            chosen->add(l);
        }
    }

    return clusters;
}

std::pair<std::list<Path<Location>>, std::vector<Cluster>>
algorithm::getPaths(const CompanyClient &companyClient, Company &company) {
    std::vector<Location> locations = companyClient.getPickupPoints();

    std::vector<Cluster> clusters = kMeans(locations, companyClient.getVehicleNumber());

    if (clusters.empty())
        clusters.emplace_back();

    std::list<Path<Location>> paths = pathFinder(company.getGraph(), company.getGarageLocation(),
                                                 companyClient.getHeadquarters(), clusters);

    std::vector<Cluster> orderedClusters;

    for (Path<Location> &path : paths)
        orderedClusters.push_back(path.getCluster());

    return make_pair(
            paths,
            orderedClusters);
}

std::list<Path<Location>>
algorithm::pathFinder(Graph<Location> &graph, const Location &source, const Location &destination,
                      const std::vector<Cluster> &clusters) {
    std::list<Path<Location>> res;
    std::vector<Cluster> clustersCopy(clusters);
    std::priority_queue<Trio<Location>, std::vector<Trio<Location>>, my_comparator> queue;

    const Vertex<Location> &sourceVertex = graph.getVertex(source);
    const Vertex<Location> &destinationVertex = graph.getVertex(destination);

    Trio<Location> current(sourceVertex);

    queue.push(current);

    while (!clustersCopy.empty()) {
        Trio<Location> min = queue.top();
        queue.pop();

        if (reverts(min.getPath()) || hasCycle(min.getPath()))
            continue;

        for (const std::shared_ptr<Edge<Location>> &child : min.getVertex().getOutgoing())
            queue.push(Trio<Location>(min, *child));

        current = min;

        for (auto it = clustersCopy.begin(); it != clustersCopy.end(); ++it) {
            Cluster cluster = *it;
            std::vector<Location> locations;
            locations.insert(locations.end(), cluster.getLocations().begin(), cluster.getLocations().end());

            if (isComplete(locations, current.getPath()) && current.getVertex() == destinationVertex) {
                Path<Location> path(current.getPath(), current.getPathCost(), *it);
                res.push_back(path);
                it = clustersCopy.erase(it);
                it--;
            }
        }
    }

    return res;
}

bool algorithm::isComplete(const std::vector<Location> &locations, const list<Vertex<Location>> &path) {
    bool complete = true;

    for (const Location &location : locations) {
        Vertex<Location> elem(location);
        if (find(path.begin(), path.end(), elem) == path.end()) return false;
    }

    return complete;
}
