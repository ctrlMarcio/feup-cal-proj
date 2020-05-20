#ifndef FEUP_CAL_PROJ_LOCATION_MANAGER_H
#define FEUP_CAL_PROJ_LOCATION_MANAGER_H

#include "../../util/graph/graph.h"
#include "location.h"

class LocationManager {
public:
    explicit LocationManager(const Graph<Location> &graph);

    const vector<Location> &getLocations() const;

    bool has(Location &location);

    bool has(long id);

    Location *get(long id);

private:
    std::vector<Location> locations;
};

#endif //FEUP_CAL_PROJ_LOCATION_MANAGER_H
