
#include "algorithm.h"

struct my_comparator {
    template<typename T>
    int operator()(const Trio<T> &p1, const Trio<T> &p2) {
        return p1 > p2;
    }
};

template<class T>
inline bool relax(Vertex<T> *v, Vertex<T> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v->path;
        w->path.push_back(v);
        return true;
    } else
        return false;
}

template<class T>
void algorithm::dijkstra(Graph<T> &graph, const Vertex<T> &sourceVertex) {
    for (auto &v : graph.getVertices()) {
        v.second.dist = INF;
        v.second.path.clear();
    }

    Vertex<T> &s = graph.getVertex(sourceVertex.get());
    s.dist = 0;

    MutablePriorityQueue<Vertex<T>> q;
    q.insert(&s);
    while (!q.empty()) {
        Vertex<T> *v = q.extractMin();
        for (std::shared_ptr<Edge<T>> &e : v->getOutgoing()) {
            Vertex<T> &destinationVertex = graph.getVertex(e->getDestination()->get());
            double oldDist = destinationVertex.dist;
            if (relax(v, &destinationVertex, e->getWeight())) {
                if (oldDist == INF)
                    q.insert(&destinationVertex);
                else
                    q.decreaseKey(&destinationVertex);
            }
        }
    }
}

template<class T>
Graph<T> algorithm::reduceGraph(Graph<T> graph, const std::vector<Location> &locations) {
    Graph<T> simpleGraph;

    for (Location location: locations)
        simpleGraph.add(location);

    for (auto &source : simpleGraph.getVertices()) {
        dijkstra(graph, source.second);

        for (auto &destination : simpleGraph.getVertices()) {
            if (source.second != destination.second) {
                source.second.add(&destination.second, graph.getVertex(destination.second.get()).dist);
            }
        }
    }

    return simpleGraph;
}

template<class T>
bool algorithm::hasCycle(std::list<T> list, int lastElements) {
    if (list.size() < lastElements)
        lastElements = list.size() - list.size() % 2;

    int half = lastElements / 2;

    auto lhs = std::prev(list.end(), lastElements);
    auto rhs = std::prev(list.end(), half);

    while (rhs != list.end()) {
        while (*lhs != *rhs) {
            lhs = std::next(lhs, 2);
            rhs = std::next(rhs, 1);

            if (rhs == list.end())
                return false;
        }

        auto ll = lhs;
        auto rr = rhs;

        while (*ll == *rr) {
            ll = std::next(ll, 1);
            rr = std::next(rr, 1);

            if (rr == list.end())
                return true;
        }

        lhs = std::next(lhs, 2);
        rhs = std::next(rhs, 1);
    }

    return false;
}

template<class T>
bool algorithm::reverts(std::list<Vertex<T>> vertices) {
    if (vertices.size() < 3) return false;

    auto last = std::prev(vertices.end(), 1);

    if ((*last).getOutgoing().size() <= 1) return false;

    auto check = std::prev(vertices.end(), 3);

    return (*(last) == *(check));
}

template<class T>
std::vector<std::vector<double>> algorithm::floydWarshall(Graph<T> &graph, bool output) {
    // prepares the matrices, k = 0 if you will
    std::vector<std::vector<double>> distancesMatrix;
    std::vector<std::vector<int>> pathMatrix;

    distancesMatrix.clear();
    pathMatrix.clear();

    for (auto it = graph.getVertices().begin(); it != graph.getVertices().end(); ++it) {
        vector<double> distances;
        vector<int> paths;

        for (auto &dst : graph.getVertices()) {
            double weight = (it->second.weightTo(&dst.second));
            distances.push_back(weight);

            if (weight != INF)
                paths.push_back(it->first);
            else
                paths.push_back(-1);
        }

        distancesMatrix.push_back(distances);
        pathMatrix.push_back(paths);
    }

    for (int k = 0; k < graph.verticesCount(); ++k) {
        for (int i = 0; i < graph.verticesCount(); ++i) { // for each line

            if (distancesMatrix[i][k] == INF)
                continue;

            for (int j = 0; j < graph.verticesCount(); ++j) { // for each column
                if (distancesMatrix[k][j] != INF &&
                    distancesMatrix[i][k] + distancesMatrix[k][j] < distancesMatrix[i][j]) {
                    distancesMatrix[i][j] = distancesMatrix[i][k] + distancesMatrix[k][j];
                    pathMatrix[i][j] = pathMatrix[k][j];
                }
            }
        }

        if (output)
            std::cout << "\r" << (double) k / graph.verticesCount() * 100 << "%" << std::endl;
    }

    return distancesMatrix;
}

template<class T>
bool algorithm::isDenselyConnected(Graph<T> &graph, bool output) {
/*    std::vector<std::vector<double>> distances = algorithm::floydWarshall(graph, output);

    for (const auto& line : distances)
        for (double distance : line)
            if (distance == INF)
                return false;

    return true;*/

    auto vectors = algorithm::tarjan(graph);
    int size = vectors.size();
    if (output)
        std::cout << "Number of strongly connected components: " << size << std::endl;
    return size == 1;
}

template<class T>
std::vector<std::vector<Vertex<T> *>> algorithm::tarjan(Graph<T> &graph) {
    std::vector<std::vector<Vertex<T> *>> res;

    long index = 0;
    std::stack<Vertex<T> *> stack;

    for (auto &v : graph.getVertices())
        if (v.second.tarjanIndex == -1)
            res.push_back(tarjanStrongConnect(graph, stack, v.second, index));

    return res;
}

template<class T>
vector<Vertex<T> *> algorithm::tarjanStrongConnect(Graph<T> &graph, stack<Vertex<T> *> &tarjanStack, Vertex<T> &v, long &index) {
    v.tarjanIndex = index;
    v.tarjanLowLink = index;
    index++;

    tarjanStack.push(&v);
    v.tarjanOnStack = true;

    for (std::shared_ptr<Edge<T>> &e : v.getOutgoing()) {
        Vertex<T> &w = *(e->getDestination());

        if (w.tarjanIndex == -1) {
            algorithm::tarjanStrongConnect(graph, tarjanStack, w, index);

            v.tarjanLowLink = std::min(v.tarjanLowLink, w.tarjanLowLink);
        } else if (w.tarjanOnStack) {
            v.tarjanLowLink = std::min(v.tarjanLowLink, w.tarjanIndex);
        }
    }

    std::vector<Vertex<T> *> connectedComponent;

    if (v.tarjanLowLink == v.tarjanIndex) {
        Vertex<T> *w;

        do {
            w = tarjanStack.top();
            tarjanStack.pop();

            w->tarjanOnStack = false;
            connectedComponent.push_back(w);
        } while (*w != v);
    }

    return connectedComponent;
}
