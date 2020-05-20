#ifndef FEUP_CAL_PROJ_CLUSTER_H
#define FEUP_CAL_PROJ_CLUSTER_H

#include <vector>
#include <unordered_set>

#include "../../model/location/location.h"
#include "vertex.h"
#include "graph.h"

/**
 * @brief Redefinition of the default hash and equal function for the Location class.
 */
struct location_hash {
    int operator()(const Location &l) const {
        return l.hash();
    }

    bool operator()(const Location &lhs, const Location &rhs) const {
        return lhs == rhs;
    }
};

/**
 * @brief Represents a coherent agglomerate of a location graph's locations, given their position
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
     * @param location    the pointer wrapper of the vertex to add
     * @return          true if successful, false otherwise
     */
    bool add(const Location &location);

    /**
     * @brief Removes all the locations from the cluster
     */
    void clear();

    /**
    * @brief Returns the centroid
    *
    * @return the centroid as a pair x, y
    */
    const pair<double, double> &getCentroid() const;

    /**
     * @brief Gets the locations that the cluster holds
     *
     * @return the locations
     */
    const unordered_set<Location, location_hash> &getLocations() const;

private:
    /**
     * @brief The set of vertex pointers
     */
    std::unordered_set<Location, location_hash> locations;

    /**
     * @brief The centroid (or center of mass) of the cluster
     */
    std::pair<double, double> centroid;
};


#endif //FEUP_CAL_PROJ_CLUSTER_H
