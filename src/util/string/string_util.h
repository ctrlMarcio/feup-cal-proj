#ifndef FEUP_CAL_PROJ_STRING_UTIL_H
#define FEUP_CAL_PROJ_STRING_UTIL_H

#include <vector>
#include <string>

/**
 * @brief Contains useful functions and utilities to deal with strings.
 */
namespace string_util {
    /*!
     * Splits a string into a vector of tokens. This tokens should be delimited by a special string.
     * E.g.: When calling string_util::split("Hi my name is Abel", " "), it should return a vector with the strings
     * "Hi", "my", "name", "is", "Abel".
     *
     * @param string the string to split
     * @param delimiter the delimiter that separates tokens
     * @return a vector with all the tokens
     */
    std::vector<std::string> split(std::string &string, char delimiter);

    /*!
     * Generates a random password with a specific length.
     *
     * @param length the length of the password
     * @return the password
     */
    std::string random_password(int length);

    /*!
     * Verifies if a string is a number.
     *
     * @param s the string
     * @return true, if the string is a number. false, otherwise
     */
    bool is_number(const std::string &string);

    /*!
     * Trims a string.
     *
     * @param string the string
     * @return the trimmed string
     */
    std::string trim(const std::string &string);

}

#endif //FEUP_CAL_PROJ_STRING_UTIL_H
