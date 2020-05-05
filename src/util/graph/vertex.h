#ifndef FEUP_CAL_PROJ_VERTEX_H
#define FEUP_CAL_PROJ_VERTEX_H

#include <vector>

#include "edge.h"

using namespace std;

template<class T>
class Vertex {
	T info;

	vector<shared_ptr<Edge<T>>> outgoing;  // adj

public:
	explicit Vertex(T in);

	T getInfo() const;

	vector<shared_ptr<Edge<T>>> getAdj() const;

	shared_ptr<Edge<T>> addEdge(shared_ptr<Vertex<T>> dest, double w);
};

#include "vertex.tpp"

#endif //FEUP_CAL_PROJ_VERTEX_H