#ifndef GRAPH_H_
#define GRAPH_H_

#include <limits>
#include <vector>
#include <memory>

#include "vertex.h"

using namespace std;

template<class T>
class Graph {
	vector<shared_ptr<Vertex<T>>> vertexSet;

	shared_ptr<Vertex<T>> findVertex(const T &inf) const;

public:
	vector<shared_ptr<Vertex<T>>> getVertexSet() const;

	shared_ptr<Vertex<T>> addVertex(const T &in);

	shared_ptr<Edge<T>> addEdge(const T &source, const T &dest, double w);

};

#include "graph.tpp"

#endif /* GRAPH_H_ */