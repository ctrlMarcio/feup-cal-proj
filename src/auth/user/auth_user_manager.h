#ifndef FEUP_CAL_PROJ_AUTH_USER_MANAGER_H
#define FEUP_CAL_PROJ_AUTH_USER_MANAGER_H

#include <unordered_set>
#include <numeric>
#include "auth_user.h"

/**
 * @brief Redefinition of the default hash and equal function for the AuthUser class.
 */
struct auth_users_hash {
    int operator()(const AuthUser &obj) const {
        int v = 0;

        for (const char &element : obj.getEmail())
            v = 37 * v + (int) element;

        return v;
    }

    bool operator()(const AuthUser &user1, const AuthUser &user2) const {
        return user1 == user2;
    }
};

/**
 * @brief Represents the manager of the auth users.
 *
 * This class is responsible for handling the auth users of the application.
 */
class AuthUserManager {
public:
    /*!
     * Adds a user to the list.
     *
     * @param user  reference to a user
     * @return true, if the user is successfully added. false, otherwise
     */
    bool add(AuthUser &user);

    /*!
     * Removes a user from the list.
     *
     * @param user  reference to a user
     * @return true, if the user is successfully removed. false, otherwise
     */
    bool remove(AuthUser &user);

    /*!
     * Verifies if a user is in the list or not.
     *
     * @param user  reference to a user
     * @return true, if the user is in the list. false, otherwise
     */
    bool has(AuthUser &user) const;

    /*!
     * Verifies if a user is in the list or not.
     *
     * @param email the email of the user to verify
     * @return true, if the user is in the list. false, otherwise
     */
    bool has(const std::string &email) const;

    /*!
     * Gets the user from the list given an email.
     *
     * @param email the email of the user to get
     * @return the user, if found
     */
    const AuthUser *getUser(const std::string &email) const;

private:
    /*!
     * The list of users.
     */
    std::unordered_set<AuthUser, auth_users_hash> users;
};

#endif //FEUP_CAL_PROJ_AUTH_USER_MANAGER_H
