#include "vertex.h"

template<class T>
Vertex<T>::Vertex(T content): info(content) {}

template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
shared_ptr<Edge<T>> Vertex<T>::addEdge(shared_ptr<Vertex<T>> dest, double w) {
	auto e = make_shared<Edge<T>>(dest, w);
	this->outgoing.push_back(e);
	return e;
}

template<class T>
vector<shared_ptr<Edge<T>>> Vertex<T>::getAdj() const {
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
