#include "company_information_ui.h"

CompanyInformationUI::CompanyInformationUI(UIManager &uiManager) : uiManager(uiManager) {}

void CompanyInformationUI::run() {
    std::cout << uiManager.getHeader();

    std::cout << "Company information: " << endl << endl;

    std::cout << "Company name: " << uiManager.getCompany().getName() << endl;
    std::cout << "Company headquarters : " << uiManager.getCompany().getGarageLocation().getCity() << " - "
              << uiManager.getCompany().getGarageLocation().getLatitude() << " / "
              << uiManager.getCompany().getGarageLocation().getLongitude() << endl;
    std::cout << "Vehicle Number: " << uiManager.getCompany().getVehicleNumber() << endl;

    options.push_back(ui_util::make_option(0, "Exit"));

    int option = ui_util::getOption(options);

    if (option != 0)
        run();
}