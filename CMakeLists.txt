cmake_minimum_required(VERSION 3.15)
project(feup-cal-proj)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

option(BUILD_TESTING "Build the testing tree." ON)
# Only build tests if we are the top-level project
# Allows this to be used by super projects with `add_subdirectory`
if (BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    enable_testing()
    add_subdirectory(test)
endif ()