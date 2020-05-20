#include "client_company_representative_ui.h"
#include "company_client_information/company_client_information.h"

ClientCompanyRepresentativeUI::ClientCompanyRepresentativeUI(UIManager &uiManager) : uiManager(uiManager) {
    options.push_back(ui_util::make_line("> Client company representative"));
    options.push_back(ui_util::make_option(1, "Pickup-points"));
    options.push_back(ui_util::make_option(2, "Request vehicle increase"));
    options.push_back(ui_util::make_option(3, "View information"));
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
            uiManager.set(new PickUpPoints(uiManager));
            break;
        case 2:
            break;
        case 3:
            uiManager.set(new CompanyClientInformation(uiManager));
            break;
        default:
            break;
    }

    if (option != 0)
        run();
}
