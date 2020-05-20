#ifndef FEUP_CAL_PROJ_ADMINISTRATOR_MANAGER_H
#define FEUP_CAL_PROJ_ADMINISTRATOR_MANAGER_H

#include <unordered_set>
#include <vector>
#include "administrator.h"

/**
 * @brief Redefinition of the default hash and equal function for the Administrator class.
 */
struct administrator_hash {
    int operator()(const Administrator &obj) const {
        int v = 0;

        for (const char &element : obj.getEmail())
            v = 37 * v + (int) element;

        return v;
    }

    bool operator()(const Administrator &user1, const Administrator &user2) const {
        return user1 == user2;
    }
};

/**
 * @brief   Represents the Administrator Manager.
 */
class AdministratorManager {
public:
    /**
     * @brief Constructs the Administrator Manager.
     */
    AdministratorManager();

    /**
     * @brief Adds company to administratorSet vector.
     *
     * @return          true upon success, false otherwise
     */
    bool add(Administrator administrator);

    /**
     * @brief Removes company from administratorSet vector.
     *
     * @return          true upon success, false otherwise
     */
    bool remove(Administrator administrator);

    /**
     * @brief Adds a notification to all administrators.
     *
     * @param notification  the notification to send
     */
    void sendNotification(const std::string &notification);

    /**
     * @brief Clears all notifications.
     */
    void clearNotifications();

    /**
     * @brief Verifies if the company is valid.
     *
     * @return          true upon success, false otherwise
     */
    bool isValid(const Administrator &administrator) const;

    /*!
    * Verifies if a user is in the set or not.
    *
    * @param administrator  reference to an administrator
    * @return true, if the administrator is in the set. false, otherwise
    */
    bool has(Administrator &administrator) const;

    /*!
     * Verifies if a administrator is in the set or not.
     *
     * @param email the email of the administrator to verify
     * @return true, if the user is in the set. false, otherwise
     */
    bool has(const std::string &email) const;

    /**
    * @brief Gets Administrator Manager set.
    *
    * @return          Administrator Manager set
    */
    std::unordered_set<Administrator, administrator_hash> getAdministrators() const;

    /**
     * @brief Gets all the notifications
     *
     * @return the notifications
     */
    const std::vector<std::string> &getNotifications() const;

private:
    /**
     * @brief Administrator Manager set.
     */
    std::unordered_set<Administrator, administrator_hash> administrators;

    /**
     * @brief The vector of notifications.
     */
    std::vector<std::string> notifications;
};


#endif //FEUP_CAL_PROJ_ADMINISTRATOR_MANAGER_H
