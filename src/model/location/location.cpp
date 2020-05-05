#include "location.h"

Location::Location(long id, const std::string &city, double x, double y, double latitude, double longitude) :
        id(id), city(city), x(x), y(y), latitude(latitude), longitude(longitude) {}

long Location::getId() const {
    return id;
}

const std::string &Location::getCity() const {
    return city;
}

double Location::getX() const {
    return x;
}

double Location::getY() const {
    return y;
}

double Location::getLatitude() const {
    return latitude;
}

double Location::getLongitude() const {
    return longitude;
}
