#include "administrator.h"

Administrator::Administrator(std::string name, std::string email) : name(std::move(name)), email(std::move(email)) {}

std::string Administrator::getName() const {
    return this->name;
}

std::string Administrator::getEmail() const {
    return this->email;
}

bool Administrator::operator==(const Administrator &rhs) const {
    return email == rhs.email;
}

bool Administrator::operator!=(const Administrator &rhs) const {
    return !(rhs == *this);
}
