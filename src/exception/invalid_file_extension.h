#ifndef FEUP_CAL_PROJ_INVALID_FILE_EXTENSION_H
#define FEUP_CAL_PROJ_INVALID_FILE_EXTENSION_H


#include <stdexcept>

/**
 * @brief Represents an exception thrown whenever an attempt to work with an invalid file (e.g. non-existent) is made
 */
class InvalidFileExtension : std::runtime_error {
public:
    /**
     * @brief Constructs the exception with its message and file
     *
     * @param arg       the message
     * @param filePath  the file that caused the exception
     */
    explicit InvalidFileExtension(std::string filePath, const std::string &arg = "The file is invalid");

private:
    /**
     * @brief The message that holds information about the exception
     */
    const std::string message;

    /**
     * @brief The file that caused the exception
     */
    const std::string filePath;
};


#endif //FEUP_CAL_PROJ_INVALID_FILE_EXTENSION_H
