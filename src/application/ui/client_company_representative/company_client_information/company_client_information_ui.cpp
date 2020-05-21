#include "company_client_information_ui.h"

CompanyClientInformationUI::CompanyClientInformationUI(UIManager &uiManager) : uiManager(uiManager) {}

void CompanyClientInformationUI::run() {
    std::cout << uiManager.getHeader();

    std::cout << "Company information:" << std::endl;
    getCompanyClient();

    ui_util::displayPlaceholder();
}

void CompanyClientInformationUI::getCompanyClient() {
    const CompanyClient &company = *uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    std::cout << TAB << "Company name: " << company.getName() << std::endl;
    std::cout << TAB << "Company UUID: " << company.getUUID() << std::endl;
    std::cout << TAB << "Company vehicles: " << company.getVehicleNumber() << std::endl;
    std::cout << TAB << "Company headquarters: " << company.getHeadquarters().getId() << " at " << std::fixed
              << std::setprecision(2) << company.getHeadquarters().getX()
              << ", "
              << company.getHeadquarters().getY() << std::endl;
    std::cout << TAB << "Company pick-up points: " << company.getPickupPoints().size() << std::endl;
    std::cout << std::endl;
    std::cout << TAB << "Company representative name: " << company.getRepresentative().getName() << std::endl;
    std::cout << TAB << "Company representative email: " << company.getRepresentative().getEmail() << std::endl;
}
