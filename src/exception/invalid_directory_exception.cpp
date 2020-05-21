#include "invalid_directory_exception.h"

#include <utility>

InvalidDirectoryException::InvalidDirectoryException(std::string directoryPath, std::string arg) : runtime_error(arg),
                                                                                                   directoryPath(
                                                                                                           std::move(
                                                                                                                   directoryPath)),
                                                                                                   message(std::move(
                                                                                                           arg)) {}