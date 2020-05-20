#include "location_manager.h"

LocationManager::LocationManager(const Graph<Location> &graph) {
    for (const Vertex<Location> &vertex : graph.getVertices())
        locations.push_back(vertex.get());
}

bool LocationManager::has(Location &location) {
    return std::find(locations.begin(), locations.end(), location) != locations.end();
}

bool LocationManager::has(long id) {
    return std::find_if(locations.begin(), locations.end(), [&id](const Location &lhs) {
        return lhs.getId() == id;
    }) != locations.end();
}

const vector<Location> &LocationManager::getLocations() const {
    return locations;
}

Location *LocationManager::get(long id) {
    auto it = locations.begin();

    while (it != locations.end()) {
        if ((*it).getId() == id)
            return &(*it);
        it++;
    }

    return nullptr;
}
