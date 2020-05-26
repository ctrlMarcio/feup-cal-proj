template<typename T>
Path<T>::Path(const list<Vertex<T>> &path, double pathCost, Cluster &cluster) : path(path), pathCost(pathCost),
                                                                                cluster(cluster) {}

template<typename T>
const list<Vertex<T>> &Path<T>::getPath() const {
    return path;
}

template<typename T>
double Path<T>::getPathCost() {
    return pathCost;
}

template<typename T>
Cluster &Path<T>::getCluster() {
    return cluster;
}