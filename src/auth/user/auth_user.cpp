#include "auth_user.h"

AuthUser::AuthUser(std::string email, std::string password, std::string userRole) {
    this->email = std::move(email);
    this->password = std::move(password);
    this->userRole = std::move(userRole);
}

const std::string &AuthUser::getEmail() const {
    return email;
}

const std::string &AuthUser::getPassword() const {
    return password;
}

const std::string &AuthUser::getUserRole() const {
    return userRole;
}
