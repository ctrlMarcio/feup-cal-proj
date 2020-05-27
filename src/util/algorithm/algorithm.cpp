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

std::list<Path<Location>>
algorithm::getPaths(Graph<Location> &graph, const Location &garageLocation, const Location &headquartersLocation,
                    const std::vector<Location> &pickupPoints, int vehicleNumber, bool approximate) {

    std::vector<Cluster> clusters = kMeans(pickupPoints, vehicleNumber);

    if (clusters.empty())
        clusters.emplace_back();

    std::list<Path<Location>> paths;

    if (approximate)
        for (Cluster &cluster : clusters)
            paths.push_back(nearestNeighbourFirst(graph, garageLocation, headquartersLocation, cluster));
    else
        paths = pathFinder(graph, garageLocation, headquartersLocation, clusters);

    return paths;
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

Path<Location> algorithm::nearestNeighbourFirst(Graph<Location> &graph, Location source, const Location &destination,
                                                Cluster &cluster) {
    std::vector<Location> locations(cluster.getLocations().begin(), cluster.getLocations().end());

    std::list<Vertex<Location>> list;
    Path<Location> path(list, 0, cluster);

    while (!locations.empty()) {
        // get nearest
        std::sort(locations.begin(), locations.end(), [&source](const Location &lhs, const Location &rhs) {
            return source.euclideanDistanceTo(lhs.getX(), lhs.getY()) < source.euclideanDistanceTo(rhs.getX(), rhs.getY());
        });

        // append
        path = aStar(path, graph, source, *locations.begin(), locations, true);
        source = *locations.begin();
        locations.erase(locations.begin());
    }

    // goes to the destination
    locations.push_back(destination);
    path = aStar(path, graph, source, destination, locations, false);

    std::list<Vertex<Location>> resLocations(path.getPath());
    resLocations.push_back(graph.getVertex(destination));
    Path<Location> res(resLocations, path.getPathCost() +
                                     destination.euclideanDistanceTo(path.getPath().back().get().getX(),
                                                                     path.getPath().back().get().getY()),
                       path.getCluster());
    return res;
}

Path<Location>
algorithm::aStar(const Path<Location> &path, Graph<Location> &graph, const Location &source, const Location &dest,
                 std::vector<Location> &locations, bool dynamic) {
    for (auto &vert: graph.getVertices()) {
        vert.second.dist = INF;
        vert.second.path.clear();
        vert.second.queueIndex = 0;
    }

    Vertex<Location> &s = graph.getVertex(source);
    Vertex<Location> &d = graph.getVertex(dest);

    s.dist = source.euclideanDistanceTo(dest.getX(), dest.getY());
    MutablePriorityQueue<Vertex<Location>> queue;
    queue.insert(&s);

    while (!queue.empty()) {
        Vertex<Location> *v = queue.extractMin();

        if (*v == d) // reach destination
            break;

        // verifies if there's another important location nearby, and goes there
        if (dynamic) {
            // verifies if there's a closest point
            auto it = std::min_element(locations.begin(), locations.end(), [&v](const Location &lhs, const Location &rhs) {
                return v->get().euclideanDistanceTo(lhs.getX(), lhs.getY()) < v->get().euclideanDistanceTo(rhs.getX(), rhs.getY());
            });

            if (it != locations.begin() && it != locations.end()) {
                // calculates the new path
                Path<Location> newPath(path);
                newPath.update(v);

                newPath = aStar(newPath, graph, v->get(), *it, locations, false);

                // puts the new destination in the front
                Location newD = *it;
                locations.erase(it);
                locations.insert(locations.begin(), newD);

                return newPath;
            }
        }

        for (std::shared_ptr<Edge<Location>> &out : v->getOutgoing()) {
            Vertex<Location> &destinationVertex = graph.getVertex(out->getDestination()->get());

            double oldDist = destinationVertex.dist;
            double newDist = v->dist - v->get().euclideanDistanceTo(d.get().getX(), d.get().getY()) + out->getWeight() +
                             destinationVertex.get().euclideanDistanceTo(d.get().getX(), d.get().getY());

            //double newDist = v->dist - v->get().manhattanHeuristic(d.get()) + out->getWeight() +
            //                destinationVertex.get().manhattanHeuristic(d.get());

            if (oldDist > newDist) {
                destinationVertex.dist = newDist;
                destinationVertex.path = v->path;
                destinationVertex.path.push_back(v);

                if (oldDist == INF)
                    queue.insert(&destinationVertex);
                else
                    queue.decreaseKey(&destinationVertex);
            }
        }
    }

    Path<Location> newPath(path);
    newPath.update(&d);

    return newPath;
}

std::vector<Location> algorithm::getBounds(std::vector<Vertex<Location> *> vertices) {
    std::sort(vertices.begin(), vertices.end(), [](const Vertex<Location> *v1, const Vertex<Location> *v2) {
        return v1->get().getY() < v2->get().getY();
    });

    std::vector<Location> leftSide;
    std::vector<Location> rightSide;

    if (vertices.empty())
        return leftSide;

    double maxHeight = -1;
    double minHeight = INF;

    for (const Vertex<Location> *v : vertices) {
        maxHeight = std::max(maxHeight, v->get().getY());
        minHeight = std::min(minHeight, v->get().getY());
    }

    if (maxHeight == minHeight)
        return leftSide;

    double offset = (maxHeight - minHeight) / 3.0;

    auto max = vertices.back();

    for (double currentHeight = minHeight - offset / 2;
         currentHeight <= maxHeight + offset / 2; currentHeight += offset) {
        Location leftLocation;
        Location rightLocation;

        auto it = vertices.begin();

        Vertex<Location> *current = *it;

        double leftmost = INF;
        double rightmost = -INF;

        while (!vertices.empty() && current->get().getY() < currentHeight + offset) {
            if (current->get().getX() < leftmost) {
                leftmost = current->get().getX();
                leftLocation = current->get();
            }

            if (current->get().getX() > rightmost) {
                rightmost = current->get().getX();
                rightLocation = current->get();
            }

            vertices.erase(vertices.begin());
            current = *vertices.begin();
        }

        if (leftmost != INF)
            leftSide.push_back(leftLocation);
        if (rightmost != -INF)
            rightSide.push_back(rightLocation);
    }

    leftSide.push_back((*max).get());

    std::reverse(rightSide.begin(), rightSide.end());

    leftSide.insert(leftSide.end(), rightSide.begin(), rightSide.end());

    return leftSide;
}

std::vector<std::vector<Location>> algorithm::getBoundAreas(std::vector<std::vector<Vertex<Location> *>> vertices) {
    std::vector<std::vector<Location>> res;

    res.reserve(vertices.size());
    for (const auto &vector : vertices)
        res.push_back(getBounds(vector));

    return res;
}
