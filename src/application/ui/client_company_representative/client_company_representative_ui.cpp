#include "client_company_representative_ui.h"
#include "company_client_information/company_client_information_ui.h"
#include "vehicle/request_vehicle_change_ui.h"
#include "route/view_paths_ui.h"
#include "graph/company_client_graph_ui.h"

ClientCompanyRepresentativeUI::ClientCompanyRepresentativeUI(UIManager &uiManager) : uiManager(uiManager) {
    options.push_back(ui_util::make_line("> Company"));
    options.push_back(ui_util::make_option(1, "Pick-up points"));
    options.push_back(ui_util::make_option(2, "Request vehicle number update"));
    options.push_back(ui_util::make_option(3, "View information"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_line("> Routes"));
    options.push_back(ui_util::make_option(4, "View paths"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Logout"));
}

void ClientCompanyRepresentativeUI::run() {
    std::cout << uiManager.getHeader();
    std::cout << "Welcome to the company representative terminal interface!" << std::endl;

    int option = ui_util::getOption(options);

    switch (option) {
        case 0:
            cout << std::endl << "Logging out..." << std::endl;
            uiManager.getCurrentSession().logout();
            break;
        case 1:
            uiManager.set(new PickUpPointUI(uiManager));
            break;
        case 2:
            uiManager.set(new RequestVehicleChangeUI(uiManager));
            break;
        case 3:
            uiManager.set(new CompanyClientInformationUI(uiManager));
            break;
        case 4:
            uiManager.set(new ViewPathsUI(uiManager));
            break;
        default:
            break;
    }

    if (option != 0)
        run();
}
