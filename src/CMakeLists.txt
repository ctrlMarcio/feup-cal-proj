add_library(feup-cal-proj main.cpp
        util/graph/graph.tpp util/graph/graph.h
        util/graph/vertex.tpp util/graph/vertex.h
        util/graph/edge.tpp util/graph/edge.h
        util/graph/mutable_priority_queue.h
        util/graph/cluster.cpp util/graph/cluster.h
        util/string/ui_util.h util/string/ui_util.cpp
        util/string/string_util.cpp util/string/string_util.h
        util/algorithm/algorithm.cpp util/algorithm/algorithm.h
        util/algorithm/trio.h util/algorithm/trio.tpp
        util/algorithm/path.cpp util/algorithm/path.h
        exception/invalid_login_exception.cpp exception/invalid_login_exception.h
        exception/invalid_file_exception.cpp exception/invalid_file_exception.h
        exception/invalid_directory_exception.cpp exception/invalid_directory_exception.h
        exception/invalid_location_exception.cpp exception/invalid_location_exception.h
        exception/invalid_vertex_exception.h exception/invalid_vertex_exception.cpp
        auth/user/auth_user.cpp auth/user/auth_user.h
        auth/user/auth_user_manager.cpp auth/user/auth_user_manager.h
        auth/session/current_session.cpp auth/session/current_session.h
        model/location/location.cpp model/location/location.h
        model/company/company.cpp model/company/company.h
        model/company_client/company_client.cpp model/company_client/company_client.h
        model/company/administrator/administrator.cpp model/company/administrator/administrator.h
        model/company_client/company_representative/company_representative.cpp model/company_client/company_representative/company_representative.h
        model/company_client/company_client_manager/company_client_manager.cpp model/company_client/company_client_manager/company_client_manager.h
        model/company/administrator/administrator_manager.cpp model/company/administrator/administrator_manager.h
        model/location/location_manager.cpp model/location/location_manager.h
        application/bootstrap/bootstrap.cpp application/bootstrap/bootstrap.h
        application/ui/ui/ui_manager.cpp application/ui/ui/ui_manager.h
        application/ui/ui/ui.h
        application/ui/home/home_ui.cpp application/ui/home/home_ui.h
        application/ui/login/login_ui.h application/ui/login/login_ui.cpp
        application/ui/administrator/administrator_ui.cpp application/ui/administrator/administrator_ui.h
        application/ui/administrator/company_client/modify_company_vehicles_ui.cpp application/ui/administrator/company_client/modify_company_vehicles_ui.h
        application/ui/administrator/company_client/register_company_ui.cpp application/ui/administrator/company_client/register_company_ui.h
        application/ui/administrator/vehicle/verify_vehicles_ui.cpp application/ui/administrator/vehicle/verify_vehicles_ui.h
        application/ui/administrator/company_client/modify_company_vehicles_ui.cpp application/ui/administrator/company_client/modify_company_vehicles_ui.h
        model/location/location_manager.cpp model/location/location_manager.h
        application/ui/client_company_representative/vehicle/request_vehicle_change_ui.cpp application/ui/client_company_representative/vehicle/request_vehicle_change_ui.h
        model/location/location_manager.cpp model/location/location_manager.h
        application/ui/administrator/company/company_information_ui.cpp application/ui/administrator/company/company_information_ui.h
        application/ui/client_company_representative/company_client_information/company_client_information_ui.cpp application/ui/client_company_representative/company_client_information/company_client_information_ui.h
        application/ui/client_company_representative/client_company_representative_ui.cpp application/ui/client_company_representative/client_company_representative_ui.h
        application/ui/client_company_representative/pickup_point/pickup_point_ui.cpp application/ui/client_company_representative/pickup_point/pickup_point_ui.h
        application/ui/administrator/company_client/companies_client_information_ui.cpp application/ui/administrator/company_client/companies_client_information_ui.h
        util/gmaps/google_map.cpp util/gmaps/google_map.h
        application/ui/client_company_representative/route/view_paths_ui.cpp application/ui/client_company_representative/route/view_paths_ui.h
        application/ui/administrator/graph/view_world_graph_ui.cpp application/ui/administrator/graph/view_world_graph_ui.h
        )

add_executable(application main.cpp
        util/graph/graph.tpp util/graph/graph.h
        util/graph/vertex.tpp util/graph/vertex.h
        util/graph/edge.tpp util/graph/edge.h
        util/graph/mutable_priority_queue.h
        util/graph/cluster.cpp util/graph/cluster.h
        util/string/ui_util.h util/string/ui_util.cpp
        util/string/string_util.cpp util/string/string_util.h
        util/algorithm/algorithm.cpp util/algorithm/algorithm.h
        util/algorithm/trio.h util/algorithm/trio.tpp
        util/algorithm/path.cpp util/algorithm/path.h
        exception/invalid_login_exception.cpp exception/invalid_login_exception.h
        exception/invalid_file_exception.cpp exception/invalid_file_exception.h
        exception/invalid_directory_exception.cpp exception/invalid_directory_exception.h
        exception/invalid_location_exception.cpp exception/invalid_location_exception.h
        exception/invalid_vertex_exception.h exception/invalid_vertex_exception.cpp
        auth/user/auth_user.cpp auth/user/auth_user.h
        auth/user/auth_user_manager.cpp auth/user/auth_user_manager.h
        auth/session/current_session.cpp auth/session/current_session.h
        model/location/location.cpp model/location/location.h
        model/company/company.cpp model/company/company.h
        model/company_client/company_client.cpp model/company_client/company_client.h
        model/company/administrator/administrator.cpp model/company/administrator/administrator.h
        model/company_client/company_representative/company_representative.cpp model/company_client/company_representative/company_representative.h
        model/company_client/company_client_manager/company_client_manager.cpp model/company_client/company_client_manager/company_client_manager.h
        model/company/administrator/administrator_manager.cpp model/company/administrator/administrator_manager.h
        model/location/location_manager.cpp model/location/location_manager.h
        application/bootstrap/bootstrap.cpp application/bootstrap/bootstrap.h
        application/ui/ui/ui_manager.cpp application/ui/ui/ui_manager.h
        application/ui/ui/ui.h
        application/ui/home/home_ui.cpp application/ui/home/home_ui.h
        application/ui/login/login_ui.h application/ui/login/login_ui.cpp
        application/ui/administrator/administrator_ui.cpp application/ui/administrator/administrator_ui.h
        application/ui/administrator/company_client/modify_company_vehicles_ui.cpp application/ui/administrator/company_client/modify_company_vehicles_ui.h
        application/ui/administrator/company_client/register_company_ui.cpp application/ui/administrator/company_client/register_company_ui.h
        application/ui/administrator/vehicle/verify_vehicles_ui.cpp application/ui/administrator/vehicle/verify_vehicles_ui.h
        application/ui/administrator/company_client/modify_company_vehicles_ui.cpp application/ui/administrator/company_client/modify_company_vehicles_ui.h
        model/location/location_manager.cpp model/location/location_manager.h
        application/ui/client_company_representative/vehicle/request_vehicle_change_ui.cpp application/ui/client_company_representative/vehicle/request_vehicle_change_ui.h
        model/location/location_manager.cpp model/location/location_manager.h
        application/ui/administrator/company/company_information_ui.cpp application/ui/administrator/company/company_information_ui.h
        application/ui/client_company_representative/company_client_information/company_client_information_ui.cpp application/ui/client_company_representative/company_client_information/company_client_information_ui.h
        application/ui/client_company_representative/client_company_representative_ui.cpp application/ui/client_company_representative/client_company_representative_ui.h
        application/ui/client_company_representative/pickup_point/pickup_point_ui.cpp application/ui/client_company_representative/pickup_point/pickup_point_ui.h
        application/ui/administrator/company_client/companies_client_information_ui.cpp application/ui/administrator/company_client/companies_client_information_ui.h
        util/gmaps/google_map.cpp util/gmaps/google_map.h
        application/ui/client_company_representative/route/view_paths_ui.cpp application/ui/client_company_representative/route/view_paths_ui.h
        application/ui/administrator/graph/view_world_graph_ui.cpp application/ui/administrator/graph/view_world_graph_ui.h
        ../lib/connection.cpp ../lib/graphviewer.cpp
        application/ui/client_company_representative/graph/company_client_graph_ui.cpp application/ui/client_company_representative/graph/company_client_graph_ui.h util/view_graph/graph_view_builder.cpp util/view_graph/graph_view_builder.h application/ui/administrator/graph/verify_connectivity_ui.cpp application/ui/administrator/graph/verify_connectivity_ui.h)

target_include_directories(feup-cal-proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(feup-cal-proj PUBLIC gtest_main coverage_config)