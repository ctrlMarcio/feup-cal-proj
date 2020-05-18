#include "algorithm.h"

std::vector<Cluster> algorithm::kMeans(const Graph<Location> &graph, int clusterAmount, int iterations) {
    // initialize clusters
    auto set = graph.getVertices();
    std::vector<Cluster> clusters;
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
            cluster.clear();
        }

        // assign point to nearest cluster
        for (const Vertex<Location> &v : set) {
            double min = INF;
            Cluster *chosen = &clusters[0];

            for (Cluster &cluster : clusters) {
                double distance = v.get().euclideanDistanceTo(cluster.getCentroid().first,
                                                              cluster.getCentroid().second);
                if (distance < min) {
                    min = distance;
                    chosen = &cluster;
                }
            }

            chosen->addVertex(v);
        }
    }

    return clusters;

}
