#ifndef FEUP_CAL_PROJ_INVALID_VERTEX_EXCEPTION_H
#define FEUP_CAL_PROJ_INVALID_VERTEX_EXCEPTION_H

#include <stdexcept>

/**
 * @brief Represents an exception thrown whenever an invalid graph's vertex is required.
 */
class InvalidVertexException : public std::invalid_argument {
public:
    /*!
     * @brief Establishes a new instance of an InvalidVertexException.
     *
     * @param arg the arguments
     */
    explicit InvalidVertexException(const std::string &arg="The vertex does not exist.");

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


#endif //FEUP_CAL_PROJ_INVALID_VERTEX_EXCEPTION_H
