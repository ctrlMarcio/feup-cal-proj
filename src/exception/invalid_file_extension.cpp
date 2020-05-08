#include "invalid_file_extension.h"

#include <utility>

InvalidFileExtension::InvalidFileExtension(std::string filePath, const std::string &arg) : runtime_error(arg), filePath(std::move(filePath)), message(arg) {}
