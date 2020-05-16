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
	vector<std::shared_ptr<Edge<T>>> getOutgoing() const;

    /**
     * @brief Gets the container for the incoming edges.
     *
     * @return			the container for the incoming edges
     */
    vector<std::shared_ptr<Edge<T>>> getIncoming() const;

	/**
	 * @brief Creates and adds an outgoing edge to the vertex.
	 *
	 * @param dest		the pointer to the destination vertex
	 * @param w 		the weight of the edge
	 * @return			the pointer to the created edge
	 */
	Edge<T> *addEdge(Vertex<T> *dest, double w);

	/**
	 * @brief Calculates the weight to a given vertex
	 *
	 * @param dest  the destination vertex
	 * @return      the weight to the vertex
	 */
    double weightTo(Vertex<T> *dest);

    /**
     * @brief Gets an hash for the vertex
     *
     * @return      the hash
     */
	int hash();

	/**
	 * @brief Verifies if this vertex is equal to another one
	 *
	 * @param rhs   the other vertex
	 * @return      true if they are equal, false otherwise
	 */
    bool operator==(const Vertex &rhs) const;

    /**
     * @brief Verifies if this vertex is different of another
     *
     * @param rhs   the other vertex
     * @return      true if they are different, false otherwise
     */
    bool operator!=(const Vertex &rhs) const;

private:
	/**
	 * @brief The content of the vertex
	 */
	T info;

	/**
	 * @brief The container of outgoing edges
	 */
	vector<std::shared_ptr<Edge<T>>> outgoing;

    /**
     * @brief The container of incoming edges
     */
    vector<std::shared_ptr<Edge<T>>> incoming;
};

#include "vertex.tpp"

#endif //FEUP_CAL_PROJ_VERTEX_H