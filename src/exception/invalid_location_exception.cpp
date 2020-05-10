#include "invalid_location_exception.h"

#include <utility>

InvalidLocationException::InvalidLocationException(long id, const std::string &message = "Invalid location")
        : invalid_argument(message), message(message), id(id) {}
