#ifndef GRAPH_H_
#define GRAPH_H_

#include <limits>
#include <set>
#include <memory>

#include "vertex.h"

using namespace std;

/**
 * @brief Represents a graph.
 * A graph is a structure that contains vertexes and their connections.
 * This graph has a container with all its vertexes, and their edges are managed by them.
 *
 * @tparam T	the type that the vertex holds
 */
template<class T>
class Graph {
public:
    /**
     * @brief Gets the vertex container.
     *
     * @return		the vertex container
     */
    set<shared_ptr<Vertex<T>>> getVertexSet() const;

    /**
     * @brief Adds a vertex to the graph.
     *
     * @param content	the content of the vertex
     * @return			the pointer to the vertex added
     */
    shared_ptr<Vertex<T>> addVertex(const T &content);

    /**
     * @brief Adds an edge to the graph.
     *
     * @warning			returns \e nullptr if one of the vertexes doesn't exist
     * @param source	the content of the source vertex
     * @param dest		the content of the destination vertex
     * @param w			the weight of the edge
     * @return			the pointer to the created edge
     */
    shared_ptr<Edge<T>> addEdge(const T &source, const T &dest, double w);

    /**
     * @brief Appends locations to the graph from a file.
     *
     * @param fileName  the name of the file containing the locations
     * @param city      the name of the city described in the files
     */
    void read(std::string &fileName, const std::string &city);

private:
    /**
     * @brief The container of vertexes.
     */
    set<shared_ptr<Vertex<T>>> vertexSet;

    /**
     * @brief The regular delimiter of the files.
     */
    static const char DELIMITER = ',';

    /**
     * @brief Gets the pointer to a vertex, given its content.
     *
     * @param content	the given content
     * @return			the pointer to the vertex
     */
    shared_ptr<Vertex<T>> findVertex(const T &content) const;
};

#include "graph.tpp"

#endif /* GRAPH_H_ */