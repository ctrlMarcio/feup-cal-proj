#ifndef FEUP_CAL_PROJ_CLUSTER_H
#define FEUP_CAL_PROJ_CLUSTER_H


#include <vector>
#include <unordered_set>

#include "../../model/location/location.h"
#include "vertex.h"
#include "graph.h"

/**
 * @brief Redefinition of the default hash and equal function for the Vertex class.
 */
struct vertex_hash {
    template<class T>
    int operator()(const Vertex<T> &v) const {
        return v.hash();
    }

    template<class T>
    bool operator()(const Vertex<T> &v1, const Vertex<T> &v2) const {
        return v1 == v2;
    }
};

/**
 * @brief Represents a coherent agglomerate of a location graph's vertexes, given their position
 */
class Cluster {
public:
    /**
     * @brief Updates the centroid given the actual content of the set
     *
     * @return  the updated centroid
     */
    std::pair<double, double> updateCentroid();

    /**
     * @brief Adds a vertex to the cluster
     *
     * @param vertex    the pointer wrapper of the vertex to add
     * @return          true if successful, false otherwise
     */
    bool addVertex(const Vertex<Location> &vertex);

    /**
     * @brief Removes all the vertexes from the cluster
     */
    void clear();

    /**
    * @brief Returns the centroid
    *
    * @return the centroid as a pair x, y
    */
    const pair<double, double> &getCentroid() const;

    /**
     * @brief Gets the vertexes that the cluster holds
     *
     * @return the vertexes
     */
    const unordered_set<Vertex<Location>, vertex_hash> &getVertexes() const;

private:
    /**
     * @brief The set of vertex pointers
     */
    std::unordered_set<Vertex<Location>, vertex_hash> vertexes;

    /**
     * @brief The centroid (or center of mass) of the cluster
     */
    std::pair<double, double> centroid;
};


#endif //FEUP_CAL_PROJ_CLUSTER_H
