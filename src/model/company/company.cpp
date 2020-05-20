#include "company.h"

#include <utility>

Company::Company(std::string name, const Location &garageLocation, Graph<Location> graph, long vehicleNumber = 0)
        : name(
        std::move(name)),
          garageLocation(
                  garageLocation),
          graph(std::move(
                  graph)),
          vehicleNumber(
                  vehicleNumber), locationManager(LocationManager(this->graph)) {
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

Graph<Location> &Company::getGraph() {
    return graph;
}

long Company::getUsedVehiclesNumber() const {
    return companyClientManager.getUsedVehiclesNumber();
}

CompanyClientManager &Company::getCompanyClientManager() {
    return companyClientManager;
}

bool Company::setVehicleNumber(long vehicleNumber) {
    if (vehicleNumber < this->getUsedVehiclesNumber())
        return false;

    this->vehicleNumber = vehicleNumber;
    return true;
}

bool Company::setVehicleNumber(CompanyClient &companyClient, long companyVehicleNumber) {
    if (getUsedVehiclesNumber() - companyClient.getVehicleNumber() + companyVehicleNumber > getVehicleNumber())
        return false;
    companyClient.setVehicleNumber(companyVehicleNumber);
    return true;
}

LocationManager &Company::getLocationManager() {
    return locationManager;
}

long Company::getVehiclesLeft() const {
    return vehicleNumber - getUsedVehiclesNumber();
}

AdministratorManager &Company::getAdministratorManager() {
    return administratorManager;
}
