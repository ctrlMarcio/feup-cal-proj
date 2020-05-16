#include "vertex.h"

template<class T>
Vertex<T>::Vertex(T content): info(content) {}

template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
Edge<T> *Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	auto outgoingEdge = new Edge<T>(dest, w);
	auto incomingEdge = new Edge<T>(this, w);

	std::shared_ptr<Edge<T>> ptrOut(outgoingEdge);
    std::shared_ptr<Edge<T>> ptrIn(incomingEdge);
	this->outgoing.push_back(std::move(ptrOut));
    dest->incoming.push_back(std::move(ptrIn));

	return outgoingEdge;
}

template<class T>
vector<std::shared_ptr<Edge<T>>> Vertex<T>::getOutgoing() const {
	return outgoing;
}

template<class T>
vector<std::shared_ptr<Edge<T>>> Vertex<T>::getIncoming() const {
    return incoming;
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
