add_library(feup-cal-proj main.cpp)

add_executable(application main.cpp)

target_include_directories(feup-cal-proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(feup-cal-proj PUBLIC gtest_main)