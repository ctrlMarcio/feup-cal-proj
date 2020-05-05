#ifndef FEUP_CAL_PROJ_AUTH_USER_H
#define FEUP_CAL_PROJ_AUTH_USER_H

#include <string>

/**
 * @brief Represents an authentication user.
 *
 * The authentication user is an assistant class for the auth facade. The class is responsible for holding the
 * authentication attributes of a company's user.
 */
class AuthUser {
public:
    /**
     * @brief The administrator role.
     */
    static const std::string ADMINISTRATOR;

    /**
     * @brief The company representative role.
     */
    static const std::string COMPANY_REPRESENTATIVE;

    /**
     * @brief
     * @param email
     * @param password
     * @param userRole
     */
    AuthUser(std::string email, std::string password, std::string userRole);

    /**
     * @brief Gets the email of the user.
     *
     * @return the email of the user
     */
    const std::string &getEmail() const;

    /**
     * @brief Gets the password of the user.
     *
     * @return the password of the user
     */
    const std::string &getPassword() const;

    /**
     * @brief Gets the role of the user.
     *
     * @return the role of the user
     */
    const std::string &getUserRole() const;

private:
    /**
     * @brief The email of the user.
     */
    std::string email;

    /**
     * @brief The raw password of the user.
     */
    std::string password;

    /**
     * @brief The role of the user.
     */
    std::string userRole;
};


#endif //FEUP_CAL_PROJ_AUTH_USER_H
