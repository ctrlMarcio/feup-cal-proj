#ifndef GRAPH_H_
#define GRAPH_H_

#include <limits>
#include <vector>
#include <memory>
#include <unordered_set>
#include <mutex>

#include "pointer_wrapper.h"
#include "vertex.h"

using namespace std;

/**
 * @brief Redefinition of the default hash and equal function for the PointerWrapper class.
 */
struct pointer_wrapper_hash {
    template<class T>
    int operator()(const PointerWrapper<Vertex<T>> &obj) const {
        return obj.pointer->hash();
    }

    template<class T>
    bool operator()(const PointerWrapper<Vertex<T>> &ptr1, const PointerWrapper<Vertex<T>> &ptr2) const {
        return *ptr1.pointer == *ptr2.pointer;
    }
};

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
     * @brief The destructor
     *
     * Deletes all pointers.
     */
    virtual ~Graph();

    /**
     * @brief Default constructor
     */
    Graph();

    /**
     * @brief Copy constructor
     *
     * @warning Heavy operation
     *
     * @param graph     the graph to copy
     */
    Graph(const Graph<T> &graph);

    /**
     * @brief Adds a vertex to the graph.
     *
     * @param content	the content of the vertex
     * @return			the pointer to the vertex added
     */
    bool addVertex(const T &content);

    /**
     * @brief Adds an edge to the graph.
     *
     * @warning			returns \e nullptr if one of the vertexes doesn't exist
     * @param source	the content of the source vertex
     * @param dest		the content of the destination vertex
     * @param w			the weight of the edge
     * @return			the pointer to the created edge
     */
     Edge<T> *addEdge(const T &source, const T &dest, double w);

    /**
     * @brief Appends nodes and edges from files to the graph
     *
     * @param nodesFile         the name of the nodes' file
     * @param edgesFile         the name of the edges' file
     * @param city              the name of the city to append
     * @param mutex     the mutex to ensure thread safety
     */
    void append(const std::string &nodesFile, const std::string &edgesFile, const std::string &city, std::mutex *mutex=nullptr);

    /**
     * @brief Appends locations to the graph from a file.
     *
     * @warning         Only available for \e Location graphs.
     * @throws          InvalidFileException
     * @param fileName  the name of the file containing the locations
     * @param city      the name of the city described in the files
     * @param mutex     the mutex to assure safety
     */
    void readNodes(const std::string &fileName, const std::string &city, std::mutex *mutex=nullptr);

    /**
     * @brief Reads the edges between locations to the graph from a file.
     *
     * If an edge has an ID non existent, returns false but adds the other edges anyway.
     *
     * @warning         only available for \e Location graphs
     * @throws          InvalidFileException
     * @param fileName  the name of the file containing the edges
     * @param mutex     the mutex to assure safety
     * @return          true if the edges were successfully read, false otherwise
     */
    bool readEdges(const std::string &fileName, std::mutex *mutex=nullptr);

    /**
     * @brief Gets the vertex set
     *
     * @return  the vertex set
     */
    const unordered_set<PointerWrapper<Vertex<T>> , pointer_wrapper_hash> &getVertexSet() const;

    /**
     * @brief Gets the pointer to a vertex, given its content.
     *
     * @param content	the given content
     * @return			the pointer to the vertex
     */
    Vertex<T> *findVertex(const T &content) const;

    /**
     * @brief Gets the number of nodes.
     *
     * @return the number of nodes
     */
    long nodesAmount();

private:
    /**
     * @brief The regular delimiter of the files.
     */
    static const char DELIMITER = ',';

    /**
     * @brief The container of vertexes.
     */
    unordered_set<PointerWrapper<Vertex<T>>, pointer_wrapper_hash> vertexSet;
};

#include "graph.tpp"

#endif /* GRAPH_H_ */