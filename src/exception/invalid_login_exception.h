#ifndef FEUP_CAL_PROJ_INVALID_LOGIN_EXCEPTION_H
#define FEUP_CAL_PROJ_INVALID_LOGIN_EXCEPTION_H

#include <stdexcept>

/**
 * @brief Represents an exception thrown then a bad login is executed.
 */
class InvalidLoginException : public std::invalid_argument {
public:
    /*!
     * @brief Establishes a new instance of an InvalidLoginException.
     *
     * @param arg the arguments
     */
    explicit InvalidLoginException(const std::string &arg);

    /*!
     * Gets the error message.
     *
     * @return the message
     */
    std::string &getMessage();

private:
    /*!
     * @brief The error message.
     */
    std::string message;
};

#endif //FEUP_CAL_PROJ_INVALID_LOGIN_EXCEPTION_H
