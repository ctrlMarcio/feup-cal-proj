#include "company_client.h"

CompanyClient::CompanyClient(std::string name, CompanyRepresentative representative, Location headquarters)
        : name(name), representative(representative), headquarters(headquarters), vehicleNumber(0), uuid(1) {}

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

bool CompanyClient::addPickupPoint(Location location) {
    for (auto i: pickupPoints)
    {
        if (i.getId()==location.getId())
            return false;
    }
    pickupPoints.push_back(location);
    return true;
}

bool CompanyClient::removePickupPoint(Location location) {
    std::vector<Location>::iterator it;
    it = pickupPoints.begin();
    for (auto i: pickupPoints)
    {
        if (i.getId()==location.getId())
        {
            pickupPoints.erase(it);
            return true;
        }
        it++;
    }
    return false;
}

int CompanyClient::getVehicleNumber() const
{
    return this->vehicleNumber;
}

void CompanyClient::setVehicleNumber(int vehicleNumber) {
    this->vehicleNumber = vehicleNumber;
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
