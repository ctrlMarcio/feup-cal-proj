#ifndef FEUP_CAL_PROJ_VERTEX_H
#define FEUP_CAL_PROJ_VERTEX_H

#include <memory>
#include <vector>
#include <list>

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
	 * @brief The distance to the initial vertex in dijkstra algorithm
	 */
    double dist = INF;

    /**
	 * @brief The following vertex in the path
	 */
    std::list<Vertex<T> *> path;

    /**
	 * @brief The mutable queue index of the vertex
	 */
    int queueIndex = 0;

    long tarjanIndex = -1;

    long tarjanLowLink = -1;

    bool tarjanOnStack = false;

    /**
     * @brief Constructs the vertex given only its content.
     *
     * @param content	the content
     */
    explicit Vertex(T content);

    /**
     * @brief Creates and adds an outgoing edge to the vertex.
     *
     * @param dest		the pointer to the destination vertex
     * @param w 		the weight of the edge
     * @return			the pointer to the created edge
     */
    std::shared_ptr<Edge<T>> add(Vertex<T> *dest, double w);

    /**
     * @brief Gets the content of the vertex.
     *
     * @return 			the content of the vertex
     */
    T get() const;

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
     * @brief Gets an hash for the vertex
     *
     * @return      the hash
     */
    int hash() const;

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

    /**
     * @brief Verifies if this vertex distance is lower than another
     *
     * @param rhs   the other vertex
     * @return      true if lower, false otherwise
     */
    bool operator<(Vertex<T> &vertex) const;

    /**
     * @brief Calculates the weight to a given vertex
     *
     * @param dest  the destination vertex
     * @return      the weight to the vertex
     */
    double weightTo(Vertex<T> *dest);

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