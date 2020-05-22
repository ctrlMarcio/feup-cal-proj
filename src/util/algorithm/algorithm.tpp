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
    for (Vertex<T> &v : graph.getVertices()) {
        v.dist = INF;
        v.path.clear();
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

    for (Vertex<T> &source : simpleGraph.getVertices()) {
        dijkstra(graph, source);

        for (Vertex<T> &destination : simpleGraph.getVertices()) {
            if (source != destination) {
                source.add(&destination, graph.getVertex(destination.get()).dist);
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
bool algorithm::fazMarchaAtras(std::list<Vertex<T>> vertices) {
    if (vertices.size() < 3) return false;

    auto last = std::prev(vertices.end(), 1);

    if ((*last).getOutgoing().size() <= 1) return false;

    auto check = std::prev(vertices.end(), 3);

    return (*(last) == *(check));
}