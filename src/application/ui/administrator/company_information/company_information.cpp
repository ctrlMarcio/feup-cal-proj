#include "company_information.h"

CompanyInformation::CompanyInformation(UIManager &uiManager) : uiManager(uiManager) {}

void CompanyInformation::run() {
    std::cout << uiManager.getHeader();

    std::cout << "Company information: "<< endl << endl;

    std::cout << "Company Name: " << uiManager.getCompany().getName() << endl;
    std::cout << "Company Headquarters Location: " << uiManager.getCompany().getGarageLocation().getCity() << " - " << uiManager.getCompany().getGarageLocation().getLatitude() << " / " << uiManager.getCompany().getGarageLocation().getLongitude() << endl;
    std::cout << "Vehicle Number: " << uiManager.getCompany().getVehicleNumber() << endl;

    options.push_back(ui_util::make_option(0, "Exit"));

    int option = ui_util::getOption(options);

    if (option != 0)
        run();
}