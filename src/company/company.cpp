#include "company.h"

#include <utility>

Company::Company(string name) {
    this->name = std::move(name);
}

string Company::getName() const {
    return name;
}
