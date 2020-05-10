#ifndef FEUP_CAL_PROJ_INVALID_LOCATION_EXCEPTION_H
#define FEUP_CAL_PROJ_INVALID_LOCATION_EXCEPTION_H


#include <string>
#include <stdexcept>

class InvalidLocationException : public std::invalid_argument {
public:
    InvalidLocationException(long id, const std::string &message);

private:
    const std::string message;

    const long id;
};


#endif //FEUP_CAL_PROJ_INVALID_LOCATION_EXCEPTION_H
