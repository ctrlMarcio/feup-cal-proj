#include <algorithm>
#include "company_client.h"

long CompanyClient::NUMBER_OF_COMPANIES = 1;

CompanyClient::CompanyClient(std::string name, CompanyRepresentative representative, const Location &headquarters)
        : name(std::move(name)), representative(std::move(representative)), headquarters(headquarters),
          vehicleNumber(1), uuid(NUMBER_OF_COMPANIES++) {
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
    calculated = false;
    return true;
}

bool CompanyClient::removePickupPoint(const Location &location) {
    calculated = false;

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
    calculated = false;
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

bool CompanyClient::isCalculated() const {
    return calculated;
}

const pair<std::list<Path<Location>>, std::vector<Cluster>> &CompanyClient::getRoutes() const {
    return routes;
}

void CompanyClient::setRoutes(const pair<std::list<Path<Location>>, std::vector<Cluster>> &pair) {
    routes = pair;
    calculated = true;
}

