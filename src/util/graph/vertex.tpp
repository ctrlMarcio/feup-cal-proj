#include "vertex.h"

template<class T>
Vertex<T>::Vertex(T content): info(content) {}

template<class T>
T Vertex<T>::get() const {
	return this->info;
}

template<class T>
std::shared_ptr<Edge<T>> Vertex<T>::add(Vertex<T> *dest, double w) {
	std::shared_ptr<Edge<T>> edge = std::make_shared<Edge<T>>(this, dest, w);

	this->outgoing.push_back(edge);
    dest->incoming.push_back(edge);

	return edge;
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
int Vertex<T>::hash() const {
    return info.hash();
}
