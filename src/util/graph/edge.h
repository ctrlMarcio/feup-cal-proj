#ifndef FEUP_CAL_PROJ_EDGE_H
#define FEUP_CAL_PROJ_EDGE_H

#include <limits>

#define INF std::numeric_limits<double>::max()

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
	 * @param source        the source vertex
	 * @param destination   the destination vertex
	 * @param weight		the weight
	 */
	Edge(Vertex<T> *source, Vertex<T> *destination, double weight);

    /**
     * @brief Gets the source vertex.
     *
     * @return		the pointer to the source vertex
     */
    Vertex<T> *getSource() const;

    /**
     * @brief Gets the destination vertex.
     *
     * @return		the pointer to the destination vertex
     */
	Vertex<T> *getDestination() const;

	/**
	 * @brief Gets the weight.
	 *
	 * @return		the weight
	 */
	double getWeight() const;

private:
    /**
     * @brief The source vertex of the edge.
     */
    Vertex<T> *source;

	/**
	 * @brief The destination vertex of the edge.
	 */
	Vertex<T> *destination;

	/**
	 * @brief The weight of the edge.
	 */
	double weight;
};

#include "edge.tpp"

#endif //FEUP_CAL_PROJ_EDGE_H