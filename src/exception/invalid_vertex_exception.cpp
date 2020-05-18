#include "invalid_vertex_exception.h"

InvalidVertexException::InvalidVertexException(const std::string &arg) : invalid_argument(arg), message(arg) {}

std::string &InvalidVertexException::getMessage() {
    return message;
}