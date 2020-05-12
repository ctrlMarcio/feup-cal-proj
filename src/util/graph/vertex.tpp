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
	this->outgoing.push_back(e);
	return e;
}

template<class T>
vector<Edge<T>*> Vertex<T>::getAdj() const {
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
