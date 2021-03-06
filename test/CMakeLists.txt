cmake_minimum_required(VERSION 3.10.2)

SET(CMAKE_CXX_STANDARD 14)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

include_directories(../src/)

# Link against gtest or gtest_main as needed
add_executable(tests
        util/graph/vertex_test.cpp util/graph/edge_test.cpp
        util/graph/graph_test.cpp model/location/location_test.cpp
        util/string/util_string_test.cpp auth/session/current_session_test.cpp
        model/company_client/company_client_manager/company_client_manager_test.cpp
        model/company_client/company_client_test.cpp
        model/company_client/company_representative/company_representative_test.cpp
        model/company/administrator/administrator_test.cpp
        model/company/administrator/administrator_manager_test.cpp
        util/algorithm/algorithm_test.cpp
        util/graph/cluster_test.cpp util/algorithm/reduced_graph_test.cpp)
target_link_libraries(tests PRIVATE gtest_main feup-cal-proj)

add_test(NAME tests COMMAND tests)