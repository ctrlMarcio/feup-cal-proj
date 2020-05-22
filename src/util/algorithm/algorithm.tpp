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
