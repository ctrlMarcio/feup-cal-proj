template<class T>
shared_ptr<Vertex<T>> Graph<T>::addVertex(const T &content) {
	auto v = findVertex(content);
	if (v != nullptr)
		return v;
	v = make_shared<Vertex<T>>(content);
	vertexSet.insert(v);
	return v;
}

template<class T>
shared_ptr<Vertex<T>> Graph<T>::findVertex(const T &content) const {
	for (auto v : vertexSet)
		if (v->getInfo() == content)
			return v;
	return nullptr;
}

template<class T>
set<shared_ptr<Vertex<T>>> Graph<T>::getVertexSet() const {
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