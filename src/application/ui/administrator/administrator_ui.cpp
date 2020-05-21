#include "administrator_ui.h"
#include "vehicle/verify_vehicles_ui.h"
#include "company_client/modify_company_vehicles_ui.h"
#include "company_client/register_company_ui.h"
#include "company/company_information_ui.h"
#include "company_client/companies_client_information_ui.h"

AdministratorUI::AdministratorUI(UIManager &uiManager) : uiManager(uiManager) {
    options.push_back(ui_util::make_line("> Companies"));
    options.push_back(ui_util::make_option(1, "Register company"));
    options.push_back(ui_util::make_option(2, "Modify vehicle number of company"));
    options.push_back(ui_util::make_option(3, "View company information"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_line("> Vehicles"));
    options.push_back(ui_util::make_option(4, "Verify vehicle number"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_line("> Personal"));
    options.push_back(ui_util::make_option(5, "View company information"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Logout"));
}

void AdministratorUI::run() {
    std::cout << uiManager.getHeader();
    std::cout << "Welcome to the administrator terminal interface!" << std::endl;

    if (!uiManager.getCompany().getAdministratorManager().getNotifications().empty())
        showNotifications();

    int option = ui_util::getOption(options);

    switch (option) {
        case 0:
            cout << std::endl << "Logging out..." << std::endl;
            uiManager.getCurrentSession().logout();
            break;
        case 1:
            uiManager.set(new RegisterCompanyUI(uiManager));
            break;
        case 2:
            uiManager.set(new ModifyCompanyVehiclesUI(uiManager));
            break;
        case 3:
            uiManager.set(new CompaniesClientInformationUI(uiManager));
            break;
        case 4:
            uiManager.set(new VerifyVehiclesUI(uiManager));
            break;
        case 5:
            uiManager.set(new CompanyInformationUI(uiManager));
            break;
        default:
            break;
    }

    if (option != 0)
        run();
}

void AdministratorUI::showNotifications() {
    const std::vector<std::string> &notifications = uiManager.getCompany().getAdministratorManager().getNotifications();

    std::cout << endl;
    std::cout << "You have " << notifications.size() << " new notification";
    if (notifications.size() > 1)
        std::cout << "s";
    std::cout << ":" << std::endl;

    for (const std::string &notification : notifications)
        std::cout << " - " << notification << std::endl;

    uiManager.getCompany().getAdministratorManager().clearNotifications();
}
