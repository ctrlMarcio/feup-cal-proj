#include <chrono>
#include <iomanip>
#include <sstream>
#include <random>
#include <algorithm>
#include "string_util.h"

std::vector<std::string> string_util::split(std::string &string, char delimiter) {
    std::vector<std::string> res;

    size_t last = 0, next;
    while ((next = string.find(delimiter, last)) != std::string::npos) {
        res.push_back(string.substr(last, next - last));
        last = next + 1;
    }

    res.push_back(string.substr(last));

    return res;
}

std::string string_util::random_password(int length) {
    std::random_device rd;
    std::mt19937 mt(rd());

    const char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::stringstream password_stream;

    std::uniform_real_distribution<double> dist(0.0, (double) sizeof(characters) - .01);

    for (int i = 0; i < length; i++) {
        password_stream << characters[(int) dist(mt)];
    }

    return password_stream.str();
}

bool string_util::is_number(const std::string &string) {
    return !string.empty() && std::find_if(string.begin(),
                                           string.end(), [](char c) { return !std::isdigit(c); }) == string.end();
}

std::string string_util::trim(const std::string &string) {
    auto it_b = string.begin();
    for (; *it_b == ' '; it_b++);
    auto it_e = string.end() - 1;
    for (; *it_e == ' '; it_e--);
    int size = it_e + 1 - it_b;
    return string.substr(it_b - string.begin(), size < 0 ? 0 : size);
}
