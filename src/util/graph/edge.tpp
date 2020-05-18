template<class T>
Edge<T>::Edge(Vertex<T> *source, Vertex<T> *destination, double weight): source(source), destination(destination), weight(weight) {}

template<class T>
Vertex<T> *Edge<T>::getDestination() const {
	return destination;
}

template<class T>
double Edge<T>::getWeight() const {
	return weight;
}

template<class T>
Vertex<T> *Edge<T>::getSource() const {
    return source;
}
