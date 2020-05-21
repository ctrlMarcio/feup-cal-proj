#include <algorithm>
#include "administrator_manager.h"

AdministratorManager::AdministratorManager() {}

bool AdministratorManager::isValid(const Administrator &administrator) const {
    return !administrator.getName().empty() && !administrator.getEmail().empty();
}

bool AdministratorManager::add(Administrator administrator) {
    if (!isValid(administrator)) return false;
    if (has(administrator)) return false;
    return administrators.insert(administrator).second;
}

bool AdministratorManager::remove(Administrator administrator) {
    if (!has(administrator)) return false;
    return administrators.erase(administrator) > 0;
}

std::unordered_set<Administrator, administrator_hash> AdministratorManager::getAdministrators() const {
    return administrators;
}

bool AdministratorManager::has(Administrator &administrator) const {
    return std::find(administrators.begin(), administrators.end(), administrator) != administrators.end();
}

bool AdministratorManager::has(const std::string &email) const {
    return std::find_if(administrators.begin(), administrators.end(), [&email](const Administrator &user) {
        return user.getEmail() == email;
    }) != administrators.end();
}

void AdministratorManager::sendNotification(const std::string &notification) {
    this->notifications.push_back(notification);
}

void AdministratorManager::clearNotifications() {
    this->notifications.clear();
}

const std::vector<std::string> &AdministratorManager::getNotifications() const {
    return notifications;
}
