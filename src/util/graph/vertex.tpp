#include "vertex.h"

template<class T>
Vertex<T>::Vertex(T content): info(content) {}

template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
Edge<T> *Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	auto e = new Edge<T>(dest, w);
	std::shared_ptr<Edge<T>> ptr(e);
	this->outgoing.push_back(std::move(ptr));
	return e;
}

template<class T>
vector<std::shared_ptr<Edge<T>>> Vertex<T>::getAdj() const {
	return this->outgoing;
}

template<class T>
bool Vertex<T>::operator==(const Vertex &rhs) const {
    return info == rhs.info;
}

template<class T>
bool Vertex<T>::operator!=(const Vertex &rhs) const {
    return !(rhs == *this);
}

template<class T>
int Vertex<T>::hash() {
    return info.hash();
}

template<class T>
Vertex<T>::Vertex(const Vertex<T> &v) {
    for (auto e : v.outgoing)
        this->addEdge(e->getDest(), e->getWeight());
}

template<class T>
double Vertex<T>::weightTo(Vertex<T> *dest) {
    for (Edge<T> &edge : this->adj)
        if (edge.dest == dest)
            return edge.weight;

    if (this == dest)
        return 0;

    return INF;
}