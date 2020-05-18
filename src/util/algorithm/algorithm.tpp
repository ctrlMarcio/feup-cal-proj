struct my_comparator {
    template<typename T>
    int operator()(const Trio <T> &p1, const Trio <T> &p2) {
        return p1 > p2;
    }
};

template<class T>
bool algorithm::isComplete(Graph <T> &simplifiedGraph, const list <Vertex<T>> &path) {
    bool complete = true;

    for (const auto &elem : simplifiedGraph.getVertices())
        if (find(path.begin(), path.end(), elem) == path.end()) return false;

    return complete;
}

template<class T>
Trio <T> algorithm::getPath(Graph <T> &simplifiedGraph, const T &source, const T &destination) {
    std::priority_queue < Trio < T > , std::vector < Trio < T >>, my_comparator > queue;

    const Vertex <T> &sourceVertex = simplifiedGraph.getVertex(source);
    const Vertex <T> &destinationVertex = simplifiedGraph.getVertex(destination);

    Trio <T> current(sourceVertex);

    queue.push(current);

    while (!(current.getVertex() == destinationVertex && isComplete(simplifiedGraph, current.getPath()))) {
        Trio <T> min = queue.top();
        queue.pop();

        for (const std::shared_ptr <Edge<T>> &child : min.getVertex().getOutgoing())
            queue.push(Trio<T>(min, *child));

        current = min;
    }

    return current;
}