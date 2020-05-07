#ifndef FEUP_CAL_PROJ_CURRENT_SESSION_H
#define FEUP_CAL_PROJ_CURRENT_SESSION_H

#include "../user/auth_user.h"
#include "../user/auth_user_manager.h"

/*!
 * @brief Represents the current session.
 *
 * This class is responsible for managing the current session, this is, the current logged user and its status.
 */
class CurrentSession {
public:
    /*!
     * @brief Establishes a new instance of a CurrentSession.
     *
     * @param auth_user_manager the auth user manager
     */
    explicit CurrentSession(AuthUserManager &auth_user_manager);

    /*!
     * @brief Gets the current user.
     *
     * @return the user
     */
    AuthUser &getUser() const;

    /*!
     * @brief Tries to login a user given its information.
     *
     * @param email     the email
     * @param password  the password
     */
    bool login(const std::string &email, const std::string &password);

    /*!
     * @brief Logs out a user.
     */
    bool logout();

    /**
     * @brief Gets the logged status.
     *
     * @return true, if a user is logged. false, otherwise
     */
    bool isLogged();

private:
    /*!
     * @brief The current user.
     */
    AuthUser &current_user = *(new AuthUser("", "", ""));

    /*!
     * @brief The auth user manager.
     */
    AuthUserManager &auth_user_manager;

    /*!
     * @brief The current user status.
     */
    bool logged = false;
};

#endif //FEUP_CAL_PROJ_CURRENT_SESSION_H
