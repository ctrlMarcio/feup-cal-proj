#ifndef FEUP_CAL_PROJ_GOOGLE_MAP_H
#define FEUP_CAL_PROJ_GOOGLE_MAP_H

#include "../../util/algorithm/path.h"
#include "../../model/location/location.h"

class GoogleMap {
public:
    GoogleMap(const std::list<Path<Location>>& paths, const Location &garage, const Location &headquarters,
              const std::vector<Location> &pickupPoints);

    void show();

private:
    std::string HTML;
};


#endif //FEUP_CAL_PROJ_GOOGLE_MAP_H
