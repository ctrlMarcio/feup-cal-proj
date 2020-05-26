template<class T>
bool Graph<T>::add(const T &content) {
    //if (has(content)) return false;
    Vertex<T> vertex(content);
    vertices.insert(std::pair<int, Vertex<T>>(content.getId(), vertex));
    return true;
}

template<class T>
std::shared_ptr<Edge<T>> Graph<T>::add(const T &source, const T &dest, double w) {
    Vertex<Location> &s = getVertex(source);
    Vertex<Location> &d = getVertex(dest);

    return s.add(&d, w);
}

template<class T>
Vertex<T> &Graph<T>::getVertex(const T &content) {
    Vertex<T> tmp(content);

    auto it = vertices.find(content.getId());
    if (it == vertices.end()) {
        throw InvalidVertexException();
    }

    return it->second;
}

template<class T>
long Graph<T>::verticesCount() const {
    return this->vertices.size();
}

template<class T>
const std::map<int, Vertex<T>> &Graph<T>::getVertices() const {
    return this->vertices;
}

template<class T>
std::map<int, Vertex<T>> &Graph<T>::getVertices() {
    return this->vertices;
}

template<class T>
bool Graph<T>::has(const T &content) const {
    return std::find_if(vertices.begin(), vertices.end(), [&content](const Vertex<T> &vertex) {
        return vertex.get() == content;
    }) != vertices.end();
}