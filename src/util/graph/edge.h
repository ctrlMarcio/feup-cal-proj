#ifndef FEUP_CAL_PROJ_EDGE_H
#define FEUP_CAL_PROJ_EDGE_H

using namespace std;

template<class T>
class Vertex;

/**
 * @brief Represents a directed edge of a graph.
 *
 * An edge represents a connection to a vertex with a given weight.
 *
 * @tparam T	the type that the vertex holds
 */
template<class T>
class Edge {
public:
	/**
	 * @brief Constructs an edge with all its parameters.
	 *
	 * @param d		the destination vertex
	 * @param w		the weight
	 */
	Edge(Vertex<T> *d, double w);

	/**
	 * @brief Gets the destination vertex.
	 *
	 * @return		the pointer to the destination vertex
	 */
	Vertex<T> *getDest() const;

	/**
	 * @brief Gets the weight.
	 *
	 * @return		the weight
	 */
	double getWeight() const;

private:
	/**
	 * @brief The destination vertex of the edge.
	 */
	Vertex<T> *dest;

	/**
	 * @brief The weight of the edge.
	 */
	double weight;
};

#include "edge.tpp"

#endif //FEUP_CAL_PROJ_EDGE_H