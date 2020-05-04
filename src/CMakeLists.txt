add_library(feup-cal-proj main.cpp company/company.cpp company/company.h)

add_executable(application main.cpp company/company.cpp company/company.h)

target_include_directories(feup-cal-proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(feup-cal-proj PUBLIC gtest_main coverage_config)