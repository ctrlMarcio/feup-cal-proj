#include "algorithm.h"

std::vector<Cluster> algorithm::kMeans(const std::vector<Location> &locations, int clusterAmount, int iterations) {
    // initialize clusters
    std::vector<Cluster> clusters;
    if (clusterAmount <= 0 || iterations <= 0)
        return clusters;
    unsigned long increment = locations.size() / clusterAmount;


    auto iterator = locations.begin();
    for (int i = 0; i < clusterAmount; ++i) {
        Cluster cluster;
        cluster.add(*iterator);
        clusters.push_back(cluster);

        iterator = std::next(iterator, increment);
    }

    for (int i = 0; i < iterations; ++i) {
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

std::list<Path<Location>>
algorithm::getPaths(Graph<Location> worldGraph, const CompanyClient &companyClient, const Company &company) {
    std::list<Path<Location>> result;

    std::vector<Location> locations = companyClient.getPickupPoints();

    std::vector<Cluster> clusters = kMeans(locations, companyClient.getVehicleNumber());

    for (const Cluster &cluster : clusters) {
        std::vector<Location> clusterLocations;
        clusterLocations.insert(clusterLocations.end(), cluster.getLocations().begin(), cluster.getLocations().end());
        clusterLocations.push_back(companyClient.getHeadquarters());
        clusterLocations.push_back(company.getGarageLocation());

        Graph<Location> simplifiedGraph = reduceGraph(worldGraph, clusterLocations);

        Path<Location> path = getPath(simplifiedGraph, company.getGarageLocation(), companyClient.getHeadquarters());

        result.push_back(path);
    }

    return result;
}
