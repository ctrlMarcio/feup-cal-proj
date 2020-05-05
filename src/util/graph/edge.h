#ifndef FEUP_CAL_PROJ_EDGE_H
#define FEUP_CAL_PROJ_EDGE_H

using namespace std;

template<class T>
class Vertex;

template<class T>
class Edge {
	shared_ptr<Vertex<T>> dest;

	double weight;

public:
	Edge(shared_ptr<Vertex<T>> d, double w);

	shared_ptr<Vertex<T>> getDest() const;

	double getWeight() const;
};

#include "edge.tpp"

#endif //FEUP_CAL_PROJ_EDGE_H