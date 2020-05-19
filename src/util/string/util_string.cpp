#include <chrono>
#include <iomanip>
#include <sstream>
#include "util_string.h"

std::vector<std::string> util_string::split(std::string &string, char delimiter) {
    std::vector<std::string> res;

    size_t last = 0, next;
    while ((next = string.find(delimiter, last)) != std::string::npos) {
        res.push_back(string.substr(last, next - last));
        last = next + 1;
    }
    res.push_back(string.substr(last));

    return res;
}
