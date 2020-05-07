#include <algorithm>
#include "auth_user_manager.h"

bool AuthUserManager::add(AuthUser &user) {
    if (has(user)) return false;
    return users.insert(user).second;
}

bool AuthUserManager::remove(AuthUser &user) {
    if (!has(user)) return false;
    return users.erase(user) > 0;
}

bool AuthUserManager::has(AuthUser &user) const {
    return std::find(users.begin(), users.end(), user) != users.end();
}

bool AuthUserManager::has(const std::string &email) const {
    return std::find_if(users.begin(), users.end(), [&email](const AuthUser &user) {
        return user.getEmail() == email;
    }) != users.end();
}

const AuthUser *AuthUserManager::getUser(const std::string &email) const {
    auto it = users.begin();

    while (it != users.end()) {
        if ((*it).getEmail() == email)
            return const_cast<AuthUser *>(&(*it));
        it++;
    }

    return nullptr;
}
