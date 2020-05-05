add_library(feup-cal-proj main.cpp model/company/company.cpp model/company/company.h util/graph/graph.tpp util/graph/graph.h util/graph/vertex.tpp util/graph/vertex.h util/graph/edge.tpp util/graph/edge.h model/location/location.cpp model/location/location.h auth/user/auth_user.cpp auth/user/auth_user.h)

add_executable(application main.cpp)

target_include_directories(feup-cal-proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(feup-cal-proj PUBLIC gtest_main coverage_config)