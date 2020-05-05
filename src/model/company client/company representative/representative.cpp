#include "representative.h"

Representative::Representative(std::string name, std::string email) : name(name), email(email){}

std::string Representative::getName() const {
    return this->name;
}

std::string Representative::getEmail() const {
    return this->email;
}
