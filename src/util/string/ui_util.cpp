#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include "ui_util.h"

std::string ui_util::getCurrentDate() {
    auto now = std::chrono::system_clock::now();

    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M");
    return ss.str();
}

int ui_util::getOption(const std::vector<Option> &options) {
    std::cout << std::endl;
    std::for_each(options.begin(), options.end(), [](const Option &option) {
        std::cout << option.getLine();
    });

    std::cout << std::endl;
    std::cout << "> ";

    std::string stringOption;
    std::getline(std::cin, stringOption);

    int option;
    try {
        option = std::stoi(stringOption, nullptr, 10);
    } catch (std::invalid_argument &e) {
        std::cout << "That is not a valid option, try again..." << std::endl;
        option = getOption(options);
    }

    if (std::find_if(options.begin(), options.end(), [option](const Option &lhs) {
        return lhs.getOption() == option;
    }) == options.end()) {
        std::cout << "That is not a valid option, try again..." << std::endl;
        option = getOption(options);
    }

    return option;
}

ui_util::Option ui_util::make_option(int option, std::string desc) {
    return Option(option, std::move(desc));
}

ui_util::Option ui_util::make_empty_line() {
    return Option();
}

ui_util::Option ui_util::make_line(std::string desc) {
    return Option(std::move(desc));
}

const short ui_util::Option::NEWLINE = 0;

const short ui_util::Option::OPTION = 1;

const short ui_util::Option::LINE = 2;

ui_util::Option::Option(int option, std::string desc) : option(option), desc(std::move(desc)), type(OPTION) {}

ui_util::Option::Option() : option(-1), desc("none"), type(Option::NEWLINE) {}

ui_util::Option::Option(std::string desc) : option(-1), desc(std::move(desc)), type(Option::LINE) {}

int ui_util::Option::getOption() const {
    return option;
}

const std::string &ui_util::Option::getDescription() const {
    return desc;
}

std::string ui_util::Option::getLine() const {
    std::stringstream stream;

    if (type == OPTION)
        stream << option << " - " << desc;
    else if (type == LINE)
        stream << desc;

    stream << std::endl;

    return stream.str();
}
