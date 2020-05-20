template<typename T>
Path<T>::Path(const list<Vertex<T>> &path, double pathCost) : path(path), pathCost(pathCost) {}

template<typename T>
const list<Vertex<T>> &Path<T>::getPath() const {
    return path;
}

template<typename T>
double Path<T>::getPathCost() {
    return pathCost;
}