template<class T>
Edge<T>::Edge(shared_ptr<Vertex<T>> d, double w):  dest(d), weight(w) {}

template<class T>
shared_ptr<Vertex<T>> Edge<T>::getDest() const {
	return dest;
}

template<class T>
double Edge<T>::getWeight() const {
	return weight;
}
