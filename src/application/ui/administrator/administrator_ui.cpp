#include "administrator_ui.h"
#include "vehicle/verify_vehicles_ui.h"
#include "company_client/modify_company_vehicles_ui.h"

AdministratorUI::AdministratorUI(UIManager &uiManager) : uiManager(uiManager) {
    options.push_back(ui_util::make_line("> Companies"));
    options.push_back(ui_util::make_option(1, "Register company"));
    options.push_back(ui_util::make_option(2, "Modify vehicle number of company"));
    options.push_back(ui_util::make_option(3, "View company information"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_line("> Vehicles"));
    options.push_back(ui_util::make_option(4, "Verify vehicle number"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Logout"));
}

void AdministratorUI::run() {
    std::cout << uiManager.getHeader();
    std::cout << "Welcome to the administrator terminal interface!" << std::endl;

    int option = ui_util::getOption(options);

    switch (option) {
        case 0:
            cout << std::endl << "Logging out..." << std::endl;
            break;
        case 2:
            uiManager.set(new ModifyCompanyVehiclesUI(uiManager));
            break;
        case 4:
            uiManager.set(new VerifyVehiclesUI(uiManager));
            break;
        default:
            break;
    }

    if (option != 0)
        run();
}
