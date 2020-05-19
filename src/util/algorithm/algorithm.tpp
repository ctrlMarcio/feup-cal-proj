struct my_comparator {
    template<typename T>
    int operator()(const Trio<T> &p1, const Trio<T> &p2) {
        return p1 > p2;
    }
};

template<class T>
bool algorithm::isComplete(Graph<T> &simplifiedGraph, const list<Vertex<T>> &path) {
    bool complete = true;

    for (const auto &elem : simplifiedGraph.getVertices())
        if (find(path.begin(), path.end(), elem) == path.end()) return false;

    return complete;
}

template<class T>
Trio<T> algorithm::getPath(Graph<T> &simplifiedGraph, const T &source, const T &destination) {
    std::priority_queue<Trio<T>, std::vector<Trio<T >>, my_comparator> queue;

    const Vertex<T> &sourceVertex = simplifiedGraph.getVertex(source);
    const Vertex<T> &destinationVertex = simplifiedGraph.getVertex(destination);

    Trio<T> current(sourceVertex);

    queue.push(current);

    while (!(current.getVertex() == destinationVertex && isComplete(simplifiedGraph, current.getPath()))) {
        Trio<T> min = queue.top();
        queue.pop();

        for (const std::shared_ptr<Edge<T>> &child : min.getVertex().getOutgoing())
            queue.push(Trio<T>(min, *child));

        current = min;
    }

    return current;
}

template<class T>
inline bool relax(Vertex<T> *v, Vertex<T> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v;
        return true;
    } else
        return false;
}

template<class T>
void algorithm::dijkstra(Graph<T> &graph, const Vertex<T> &sourceVertex) {
    for (Vertex<T> &v : graph.getVertices()) {
        v.dist = INF;
        v.path = nullptr;
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
Graph<T> algorithm::graph_reduction(Graph<T> graph, const std::vector<Location> &locations) {
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