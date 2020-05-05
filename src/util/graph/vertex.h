#ifndef FEUP_CAL_PROJ_VERTEX_H
#define FEUP_CAL_PROJ_VERTEX_H

#include <set>

#include "edge.h"

using namespace std;

/**
 * Represents a graph's vertex, holding its content and outgoing edges.
 *
 * @tparam T	the type that the vertex holds
 */
template<class T>
class Vertex {
public:
	/**
	 * Constructs the vertex given only its content.
	 *
	 * @param content	the content
	 */
	explicit Vertex(T content);

	/**
	 * Gets the content of the vertex.
	 *
	 * @return 			the content of the vertex
	 */
	T getInfo() const;

	/**
	 * Gets the container for the outgoing edges.
	 *
	 * @return			the container for the outgoing edges
	 */
	set<shared_ptr<Edge<T>>> getAdj() const;

	/**
	 * Creates and adds an outgoing edge to the vertex.
	 *
	 * @param dest		the pointer to the destination vertex
	 * @param w 		the weight of the edge
	 * @return			the pointer to the created edge
	 */
	shared_ptr<Edge<T>> addEdge(shared_ptr<Vertex<T>> dest, double w);

private:
	/**
	 * The content of the vertex.
	 */
	T info;

	/**
	 * The container of outgoing edges.
	 */
	set<shared_ptr<Edge<T>>> outgoing;  // adj
};

#include "vertex.tpp"

#endif //FEUP_CAL_PROJ_VERTEX_H