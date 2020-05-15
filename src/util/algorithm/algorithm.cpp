#include "algorithm.h"

std::vector<Cluster> algorithm::kMeans(const Graph<Location> &graph, int clusterAmount, int iterations) {
    // initialize clusters
    auto set = graph.getVertexSet();
    std::vector<Cluster> clusters(clusterAmount);
    unsigned long increment = set.size() / clusterAmount;

    if (clusterAmount <= 0 || iterations <= 0)
        return clusters;

    auto iterator = set.begin();
    for (int i = 0; i < clusterAmount; ++i) {
        Cluster cluster;
        cluster.addVertex(*iterator);
        clusters.push_back(cluster);

        iterator = std::next(iterator, increment);
    }

    for (int i = 0; i < iterations; ++i) {
        // compute centroids and clear the clusters
        for (Cluster &cluster : clusters) {
            cluster.updateCentroid();
            clusters.clear();
        }

        // assign point to nearest cluster
        for (const PointerWrapper<Vertex<Location>> &ptr : set) {
            double min = INF;
            Cluster chosen = clusters[0];

            for (const Cluster &cluster : clusters) {
                double distance = ptr.getPointer()->getInfo().euclideanDistanceTo(cluster.getCentroid().first, cluster.getCentroid().second);
                if (distance < min) {
                    min = distance;
                    chosen = cluster;
                }
            }

            chosen.addVertex(ptr);
        }
    }

    return clusters;

}