#include "company.h"

Company::Company(std::string name, Location garageLocation, long vehicleNumber = 0) : name(std::move(name)),
                                                                                      garageLocation(
                                                                                              std::move(
                                                                                                      garageLocation)),
                                                                                      vehicleNumber(vehicleNumber) {
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
