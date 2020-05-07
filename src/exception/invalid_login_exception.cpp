#include "invalid_login_exception.h"

InvalidLoginException::InvalidLoginException(const std::string &arg) : invalid_argument(arg), message(arg) {}

std::string &InvalidLoginException::getMessage() {
    return message;
}
