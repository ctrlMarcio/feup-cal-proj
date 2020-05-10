#include "company.h"

#include <utility>

Company::Company(std::string name, Location garageLocation, Graph<Location> graph, long vehicleNumber = 0) : name(
        std::move(name)),
                                                                                                             garageLocation(
                                                                                                                     std::move(
                                                                                                                             garageLocation)),
                                                                                                             graph(std::move(
                                                                                                                     graph)),
                                                                                                             vehicleNumber(
                                                                                                                     vehicleNumber) {
}

const std::string &Company::getName() const {
    return name;
}

long Company::getVehicleNumber() const {
    return vehicleNumber;
}

const Location &Company::getGarageLocation() const {
    return garageLocation;
}

const Graph<Location> &Company::getGraph() const {
    return graph;
}
