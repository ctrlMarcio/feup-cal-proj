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

    /**
     * @brief Replaces a given string in another string
     *
     * @link https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
     *
     * @param str   the string
     * @param from  the text to be replace
     * @param to    the text to replace
     * @return  true, if the string is successfully replaced. false, otherwise
     */
    bool replace(std::string &str, const std::string &from, const std::string &to);

    std::string toJSONObject(std::vector<std::pair<std::string, std::string>> values);
}

#endif //FEUP_CAL_PROJ_STRING_UTIL_H
