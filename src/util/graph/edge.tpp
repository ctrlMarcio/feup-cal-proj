template<class T>
Edge<T>::Edge(Vertex<T> *d, double w):  dest(d), weight(w) {}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
	return dest;
}

template<class T>
double Edge<T>::getWeight() const {
	return weight;
}
