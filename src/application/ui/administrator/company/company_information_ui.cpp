#include "company_information_ui.h"

CompanyInformationUI::CompanyInformationUI(UIManager &uiManager) : uiManager(uiManager) {}

void CompanyInformationUI::run() {
    std::cout << uiManager.getHeader();

    std::cout << "Company information:" << std::endl;
    Company &company = uiManager.getCompany();

    std::cout << TAB << "Company name: " << company.getName() << std::endl;
    std::cout << TAB << "Company vehicles: " << company.getVehicleNumber() << std::endl;
    std::cout << TAB << "Company garage: " << company.getGarageLocation().getId() << " at " << std::fixed
              << std::setprecision(2) << company.getGarageLocation().getX()
              << ", "
              << company.getGarageLocation().getY() << std::endl;
    std::cout << std::endl;
    std::cout << TAB << "Client companies registered: " << company.getCompanyClientManager().getCompanies().size()
              << std::endl;
    std::cout << std::endl;
    std::cout << TAB << "Vehicles used: " << company.getVehiclesLeft() << std::endl;
    std::cout << TAB << "Vehicles available: " << company.getUsedVehiclesNumber() << std::endl;

    ui_util::displayPlaceholder();
}