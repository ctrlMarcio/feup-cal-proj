#include "company_representative.h"

CompanyRepresentative::CompanyRepresentative(std::string name, std::string email) : name(name), email(email){}

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
