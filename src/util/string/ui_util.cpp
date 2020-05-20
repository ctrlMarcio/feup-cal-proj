#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "ui_util.h"
#include "string_util.h"

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
        std::cout << std::endl << "That is not a valid option, try again..." << std::endl;
        option = getOption(options);
    }

    if (std::find_if(options.begin(), options.end(), [option](const Option &lhs) {
        return lhs.getOption() == option;
    }) == options.end()) {
        std::cout << std::endl << "That is not a valid option, try again..." << std::endl;
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

std::string ui_util::getString(const std::string &description) {
    std::cout << description;

    std::string stringOption;
    std::getline(std::cin, stringOption);

    if (string_util::trim(stringOption).empty()) {
        std::cout << std::endl << "The input is empty, try again..." << std::endl << std::endl;
        stringOption = ui_util::getString(description);
    }

    return stringOption;
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

int ui_util::getInteger(const std::string &description) {
	std::string string = getString(description);

	int number ;

	try {
		number = std::stoi(string);
	} catch (const std::out_of_range &e) {
		std::cout << "The number is out of range, try again..." << std::endl;
		number = getInteger(description);
	} catch (const std::invalid_argument &e) {
		std::cout << string << " is not a valid number, try again..." << std::endl;
		number = getInteger(description);
	}

	return number;
}

long ui_util::getLong(const std::string &description) {
	std::string string = getString(description);

	long number;

	try {
		number = std::stol(string);
	} catch (const std::out_of_range &e) {
		std::cout << "The number is out of range, try again..." << std::endl;
		number = getInteger(description);
	} catch (const std::invalid_argument &e) {
		std::cout << string << " is not a valid number, try again..." << std::endl;
		number = getInteger(description);
	}

	return number;
}
