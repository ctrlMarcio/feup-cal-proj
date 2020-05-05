#include "administrator.h"

Administrator::Administrator(std::string name, std::string email) : name(name), email(email) {}

std::string Administrator::getName() const {
    return this->name;
}

std::string Administrator::getEmail() const {
    return this->email;
}
