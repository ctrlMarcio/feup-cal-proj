#include "location.h"

#include <cmath>

Location::Location(long id, const std::string &city, double x, double y, double latitude, double longitude) :
        id(id), city(city), x(x), y(y), latitude(latitude), longitude(longitude) {}

Location::Location(const Location &location) {
    this->id = location.getId();
    this->city = location.getCity();
    this->x = location.getX();
    this->y = location.getY();
    this->latitude = location.getLatitude();
    this->longitude = location.getLongitude();
}

Location::Location() = default;

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

bool Location::operator==(const Location &rhs) const {
    return id == rhs.id;
}

bool Location::operator!=(const Location &rhs) const {
    return !(rhs == *this);
}

int Location::hash() const {
    return id;
}

double Location::euclideanDistanceTo(double x, double y) const {
    return sqrt(pow(x - this->x, 2) + pow(y - this->y, 2));
}

double Location::manhattanHeuristic(const Location &rhs) const {
    double xChange = abs(this->x - rhs.getX());
    double yChange = abs(this->y - rhs.getY());

    return xChange + yChange;
}
