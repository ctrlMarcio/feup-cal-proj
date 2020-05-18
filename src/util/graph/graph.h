#ifndef GRAPH_H_
#define GRAPH_H_

#include <limits>
#include <vector>
#include <memory>
#include <unordered_set>
#include <mutex>

#include "vertex.h"

/**
 * @brief Represents a graph.
 *
 * A graph is a structure that contains vertexes and their connections.
 * This graph has a container with all its vertexes, and their edges are managed by them.
 *
 * @tparam T	the type that the vertex holds
 */
template<class T>
class Graph {
public:
    /**
     * @brief Adds a vertex to the graph.
     *
     * @param content	the content of the vertex
     * @return			true, if the vertex is successfully added. false, otherwise
     */
    bool add(const T &content);

    /**
     * @brief Verifies if a vertex is in the graph.
     *
     * @param content   the content of the vertex
     * @return true, if the vertex is in the graph. false, otherwise
     */
    bool has(const T &content) const;

    /**
     * @brief Adds an edge to the graph.
     *
     * @warning			returns \e nullptr if one of the vertexes doesn't exist
     * @throws          InvalidVertexException
     * @param source	the content of the source vertex
     * @param dest		the content of the destination vertex
     * @param w			the weight of the edge
     * @return			the pointer to the created edge
     */
     std::shared_ptr<Edge<T>> add(const T &source, const T &dest, double w);

    /**
     * @brief Gets the pointer to a vertex, given its content.
     *
     * @throws          InvalidVertexException
     * @param content	the given content
     * @return			the pointer to the vertex
     */
    Vertex<T> &getVertex(const T &content);

    /**
     * @brief Gets the vertex set
     *
     * @return  the vertex set
     */
    const std::vector<Vertex<T>> &getVertices() const;

    /**
     * @brief Gets the number of nodes.
     *
     * @return the number of nodes
     */
    long verticesCount() const;

    void dijkstra(const T &s);

    Vertex<T> * initSingleSource(const T &orig);

    bool relax(Vertex<T> *v, Vertex<T> *w, double weight);

    double ** W = nullptr;   // dist

    int **P = nullptr;   // path

private:
    /**
     * @brief The container of vertexes.
     */
    std::vector<Vertex<T>> vertices;
};

#include "graph.tpp"

#endif /* GRAPH_H_ */