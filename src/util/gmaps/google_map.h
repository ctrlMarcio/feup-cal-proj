#ifndef FEUP_CAL_PROJ_GOOGLE_MAP_H
#define FEUP_CAL_PROJ_GOOGLE_MAP_H

#include "../../util/algorithm/path.h"
#include "../../model/location/location.h"
#include "../graph/cluster.h"

class GoogleMap {
public:
    explicit GoogleMap(const std::vector<std::vector<Location>> &bounds);

    explicit GoogleMap(const std::vector<Location> &locations);

    GoogleMap(const std::list<Path<Location>> &paths, const Location &garage, const Location &headquarters);

    void show();

private:
    static int ID;

    std::string HTML;
};


#endif //FEUP_CAL_PROJ_GOOGLE_MAP_H
