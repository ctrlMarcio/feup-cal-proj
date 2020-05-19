add_library(feup-cal-proj main.cpp
        model/company/company.cpp model/company/company.h
        util/graph/graph.tpp util/graph/graph.h
        util/graph/vertex.tpp util/graph/vertex.h
        util/graph/edge.tpp util/graph/edge.h
        model/location/location.cpp model/location/location.h
        auth/user/auth_user.cpp auth/user/auth_user.h
        model/company_client/company_client.cpp model/company_client/company_client.h
        model/company/administrator/administrator.cpp model/company/administrator/administrator.h
        model/company_client/company_representative/company_representative.cpp model/company_client/company_representative/company_representative.h
        model/company_client/company_client_manager/company_client_manager.cpp model/company_client/company_client_manager/company_client_manager.h
        model/company/administrator/administrator_manager.cpp model/company/administrator/administrator_manager.h
        util/string/util_string.cpp util/string/util_string.h
        auth/user/auth_user_manager.cpp auth/user/auth_user_manager.h
        auth/session/current_session.cpp auth/session/current_session.h
        exception/invalid_login_exception.cpp exception/invalid_login_exception.h
        exception/invalid_file_exception.cpp exception/invalid_file_exception.h
        application/bootstrap/bootstrap.cpp application/bootstrap/bootstrap.h
        exception/invalid_directory_exception.cpp exception/invalid_directory_exception.h
        exception/invalid_location_exception.cpp exception/invalid_location_exception.h
        util/algorithm/algorithm.cpp util/algorithm/algorithm.h util/algorithm/algorithm.tpp
        util/graph/cluster.cpp util/graph/cluster.h
        util/algorithm/trio.h util/algorithm/trio.tpp
        exception/invalid_vertex_exception.h exception/invalid_vertex_exception.cpp
        application/ui/ui/ui_manager.cpp application/ui/ui/ui_manager.h
        application/ui/ui/ui.h
        application/ui/home/home_ui.cpp application/ui/home/home_ui.h
        util/graph/mutable_priority_queue.h)

add_executable(application main.cpp
        model/company/company.cpp model/company/company.h
        util/graph/graph.tpp util/graph/graph.h
        util/graph/vertex.tpp util/graph/vertex.h
        util/graph/edge.tpp util/graph/edge.h
        model/location/location.cpp model/location/location.h
        auth/user/auth_user.cpp auth/user/auth_user.h
        model/company_client/company_client.cpp model/company_client/company_client.h
        model/company/administrator/administrator.cpp model/company/administrator/administrator.h
        model/company_client/company_representative/company_representative.cpp model/company_client/company_representative/company_representative.h
        model/company_client/company_client_manager/company_client_manager.cpp model/company_client/company_client_manager/company_client_manager.h
        model/company/administrator/administrator_manager.cpp model/company/administrator/administrator_manager.h
        util/string/util_string.cpp util/string/util_string.h
        auth/user/auth_user_manager.cpp auth/user/auth_user_manager.h
        auth/session/current_session.cpp auth/session/current_session.h
        exception/invalid_login_exception.cpp exception/invalid_login_exception.h
        exception/invalid_file_exception.cpp exception/invalid_file_exception.h
        application/bootstrap/bootstrap.cpp application/bootstrap/bootstrap.h
        exception/invalid_directory_exception.cpp exception/invalid_directory_exception.h
        exception/invalid_location_exception.cpp exception/invalid_location_exception.h
        util/algorithm/algorithm.cpp util/algorithm/algorithm.h util/algorithm/algorithm.tpp
        util/graph/cluster.cpp util/graph/cluster.h
        util/algorithm/trio.h util/algorithm/trio.tpp
        exception/invalid_vertex_exception.h exception/invalid_vertex_exception.cpp
        application/ui/ui/ui_manager.cpp application/ui/ui/ui_manager.h
        application/ui/ui/ui.h
        application/ui/home/home_ui.cpp application/ui/home/home_ui.h
        util/graph/mutable_priority_queue.h)

target_include_directories(feup-cal-proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(feup-cal-proj PUBLIC gtest_main coverage_config)