template<class T>
shared_ptr<Vertex<T>> Graph<T>::addVertex(const T &in) {
	auto v = findVertex(in);
	if (v != nullptr)
		return v;
	v = make_shared<Vertex<T>>(in);
	vertexSet.push_back(v);
	return v;
}

template<class T>
shared_ptr<Vertex<T>> Graph<T>::findVertex(const T &inf) const {
	for (auto v : vertexSet)
		if (v->getInfo() == inf)
			return v;
	return nullptr;
}

template<class T>
vector<shared_ptr<Vertex<T>>> Graph<T>::getVertexSet() const {
	return this->vertexSet;
}

template<class T>
shared_ptr<Edge<T>> Graph<T>::addEdge(const T &source, const T &dest, double w) {
	auto s = findVertex(source);
	auto d = findVertex(dest);
	if (s == nullptr || d == nullptr)
		return nullptr;
	else
		return s->addEdge(d, w);
}