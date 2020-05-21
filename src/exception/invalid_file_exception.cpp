#include "invalid_file_exception.h"

#include <utility>

InvalidFileException::InvalidFileException(std::string filePath, const std::string &arg) : runtime_error(arg), filePath(
        std::move(filePath)), message(arg) {}
