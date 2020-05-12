#include "company_representative.h"

#include <utility>

CompanyRepresentative::CompanyRepresentative(std::string name, std::string email) : name(std::move(name)), email(std::move(email)){}

std::string CompanyRepresentative::getName() const {
    return this->name;
}

std::string CompanyRepresentative::getEmail() const {
    return this->email;
}

bool CompanyRepresentative::operator==(const CompanyRepresentative &rhs) const {
    return email == rhs.email;
}

bool CompanyRepresentative::operator!=(const CompanyRepresentative &rhs) const {
    return !(rhs == *this);
}
