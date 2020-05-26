#include <algorithm>
#include "company_client.h"

long CompanyClient::NUMBER_OF_COMPANIES = 1;

CompanyClient::CompanyClient(std::string name, CompanyRepresentative representative, const Location &headquarters)
        : name(std::move(name)), representative(std::move(representative)), headquarters(headquarters),
          vehicleNumber(1), uuid(NUMBER_OF_COMPANIES++) {
    resetRoutes();
}

std::string CompanyClient::getName() const {
    return this->name;
}

CompanyRepresentative CompanyClient::getRepresentative() const {
    return this->representative;
}

Location CompanyClient::getHeadquarters() const {
    return this->headquarters;
}

std::vector<Location> CompanyClient::getPickupPoints() const {
    return this->pickupPoints;
}

bool CompanyClient::addPickupPoint(const Location &location) {
    if (hasPickupPoint(location)) return false;
    pickupPoints.push_back(location);
    resetRoutes();
    return true;
}

bool CompanyClient::removePickupPoint(const Location &location) {
    resetRoutes();

    std::vector<Location>::iterator it;
    it = pickupPoints.begin();
    for (auto i: pickupPoints) {
        if (i.getId() == location.getId()) {
            pickupPoints.erase(it);
            return true;
        }
        ++it;
    }
    return false;
}

int CompanyClient::getVehicleNumber() const {
    return this->vehicleNumber;
}

void CompanyClient::setVehicleNumber(int vehicleNumber) {
    this->vehicleNumber = vehicleNumber;
    resetRoutes();
}

long CompanyClient::getUUID() const {
    return uuid;
}

bool CompanyClient::operator==(const CompanyClient &rhs) const {
    return uuid == rhs.uuid;
}

bool CompanyClient::operator!=(const CompanyClient &rhs) const {
    return !(rhs == *this);
}

bool CompanyClient::hasPickupPoint(const Location &location) {
    return std::find(pickupPoints.begin(), pickupPoints.end(), location) != pickupPoints.end();
}

const std::list<Path<Location>> &CompanyClient::getRoutes(bool returning) const {
    return (returning) ? getReturnRoutes() : getMainRoutes();
}

const std::list<Path<Location>> &CompanyClient::getMainRoutes() const {
    return routes.first;
}

const std::list<Path<Location>> &CompanyClient::getReturnRoutes() const {
    return returnRoutes.first;
}

void CompanyClient::setRoutes(const std::list<Path<Location>> &path) {
    routes.first = path;
    routes.second = true;
}

void CompanyClient::setReturnRoutes(const std::list<Path<Location>> &path) {
    returnRoutes.first = path;
    returnRoutes.second = true;
}

void CompanyClient::resetRoutes() {
    routes.second = false;
    returnRoutes.second = false;
}

bool CompanyClient::isRouteCalculated() const {
    return routes.second;
}

bool CompanyClient::isReturnRouteCalculated() const {
    return returnRoutes.second;
}
