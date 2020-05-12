#ifndef FEUP_CAL_PROJ_VERTEX_H
#define FEUP_CAL_PROJ_VERTEX_H

#include <set>

#include "edge.h"

using namespace std;

/**
 * @brief Represents a graph's vertex, holding its content and outgoing edges.
 *
 * @tparam T	the type that the vertex holds
 */
template<class T>
class Vertex {
public:
	/**
	 * @brief Constructs the vertex given only its content.
	 *
	 * @param content	the content
	 */
	explicit Vertex(T content);

	/**
	 * @brief Copy constructor
	 *
	 * Copies whats inside the edges, not just their pointers.
	 *
	 * @param v			the vertex to copy from
	 */
	Vertex(const Vertex<T> &v);

	/**
	 * @brief Gets the content of the vertex.
	 *
	 * @return 			the content of the vertex
	 */
	T getInfo() const;

	/**
	 * @brief Gets the container for the outgoing edges.
	 *
	 * @return			the container for the outgoing edges
	 */
	vector<std::shared_ptr<Edge<T>>> getAdj() const;

	/**
	 * @brief Creates and adds an outgoing edge to the vertex.
	 *
	 * @param dest		the pointer to the destination vertex
	 * @param w 		the weight of the edge
	 * @return			the pointer to the created edge
	 */
	Edge<T> *addEdge(Vertex<T> *dest, double w);

	int hash();

    bool operator==(const Vertex &rhs) const;

    bool operator!=(const Vertex &rhs) const;

private:
	/**
	 * @brief The content of the vertex.
	 */
	T info;

	/**
	 * @brief The container of outgoing edges.
	 */
	vector<std::shared_ptr<Edge<T>>> outgoing;  // adj
};

#include "vertex.tpp"

#endif //FEUP_CAL_PROJ_VERTEX_H