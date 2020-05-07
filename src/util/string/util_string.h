#ifndef FEUP_CAL_PROJ_UTIL_STRING_H
#define FEUP_CAL_PROJ_UTIL_STRING_H

#include <vector>
#include <string>

/**
 * @brief Contains useful functions and utilities to deal with strings.
 */
namespace util_string {
    /**
     * @brief           Splits a string into a vector.
     *
     * @param string    the string to split
     * @param delimiter the delimiter
     * @return          the created vector
     */
    std::vector<std::string> split(std::string &string, char delimiter);
}

#endif //FEUP_CAL_PROJ_UTIL_STRING_H
