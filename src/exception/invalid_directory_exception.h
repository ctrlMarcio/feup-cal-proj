#ifndef FEUP_CAL_PROJ_INVALID_DIRECTORY_EXCEPTION_H
#define FEUP_CAL_PROJ_INVALID_DIRECTORY_EXCEPTION_H


#include <string>
#include <stdexcept>

/**
 * @brief Represents an exception thrown whenever an attempt to work with an invalid directory (e.g. non-existent) is made
 */
class InvalidDirectoryException : std::runtime_error {
public:
    /**
     * @brief Constructs the exception with its message and path
     *
     * @param arg           the message
     * @param directoryPath the directory that caused the exception
     */
    explicit InvalidDirectoryException(std::string direcoryPath, std::string arg = "The directory is invalid");

private:
    /**
     * @brief The message that holds information about the exception
     */
    const std::string message;

    /**
     * @brief The directory path that caused the exception
     */
    const std::string directoryPath;
};


#endif //FEUP_CAL_PROJ_INVALID_DIRECTORY_EXCEPTION_H
