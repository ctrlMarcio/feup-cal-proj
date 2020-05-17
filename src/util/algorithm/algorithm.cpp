#include "algorithm.h"
#include "trio.h"

std::vector<Cluster> algorithm::kMeans(const Graph<Location> &graph, int clusterAmount, int iterations) {
    // initialize clusters
    auto set = graph.getVertexSet();
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
        for (const PointerWrapper<Vertex<Location>> &ptr : set) {
            double min = INF;
            Cluster *chosen = &clusters[0];

            for (Cluster &cluster : clusters) {
                double distance = ptr.getPointer()->getInfo().euclideanDistanceTo(cluster.getCentroid().first,
                                                                                  cluster.getCentroid().second);
                if (distance < min) {
                    min = distance;
                    chosen = &cluster;
                }
            }

            chosen->addVertex(ptr);
        }
    }

    return clusters;

}

template<class T>
bool isComplete(const Graph<T> &simplifiedGraph, std::list<Vertex<T>> path) {
    bool complete = true;

    for (const auto &elem : simplifiedGraph.getVertexSet())
        if (find(path.begin(), path.end(), *elem.getPointer()) == path.end()) return false;

    return complete;
}

template<class T>
list<Vertex<T>> algorithm::getPath(const Graph<T> &simplifiedGraph, const T &source,
                                   const T &destination) {
    std::priority_queue<Trio<T>, std::greater<Trio<T>>> queue;

    Trio<T> current(source);

    queue.push(current);

    while (current.getVertex() == source && isComplete(simplifiedGraph, current.getPath())) {
        const Trio<T> &min = queue.top();
        queue.pop();

        for (const std::shared_ptr<Edge<T>> &child : min.getVertex().getOutgoing())
            queue.push(Trio<T>(min, *child));

        current = min;
    }

    return current.getPath();
}
