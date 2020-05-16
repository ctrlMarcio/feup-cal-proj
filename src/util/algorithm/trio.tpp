#include "trio.h"

template<class T>
Trio<T>::Trio(const Vertex<T> &vertex) : vertex(vertex), pathCost(0) {
    path.push_back(vertex);
}

template<class T>
Trio<T>::Trio(const Trio<T> &source, const Edge<T> &edge) : vertex(*edge.getDest()), path(source.path) {
    path.push_back(*edge.getDest());
    pathCost = source.pathCost + edge.getWeight();
}

template<class T>
const Vertex<T> &Trio<T>::getVertex() const {
    return vertex;
}

template<class T>
list<Vertex<T>> &Trio<T>::getPath() const {
    return path;
}

template<class T>
double Trio<T>::getPathCost() const {
    return pathCost;
}

template<class T>
bool Trio<T>::operator<(const Trio &rhs) const {
    return pathCost < rhs.pathCost;
}

template<class T>
bool Trio<T>::operator>(const Trio &rhs) const {
    return rhs < *this;
}

template<class T>
bool Trio<T>::operator<=(const Trio &rhs) const {
    return !(rhs < *this);
}

template<class T>
bool Trio<T>::operator>=(const Trio &rhs) const {
    return !(*this < rhs);
}
