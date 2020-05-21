#include "companies_client_information_ui.h"

CompaniesClientInformationUI::CompaniesClientInformationUI(UIManager &uiManager) : uiManager(uiManager) {
    for (const CompanyClient &companyClient : uiManager.getCompany().getCompanyClientManager().getCompanies())
        options.push_back(ui_util::make_option(companyClient.getUUID(), companyClient.getName()));

    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Return"));
}

void CompaniesClientInformationUI::run() {
    std::cout << uiManager.getHeader();

    if (uiManager.getCompany().getCompanyClientManager().getCompanies().empty()) {
        std::cout << "There are no companies registered!" << std::endl;
        ui_util::displayPlaceholder();
        return;
    }

    std::cout << "Select a company from the list..." << std::endl;

    long option = ui_util::getOption(options);

    if (option == 0) {
        std::cout << std::endl << "Returning..." << std::endl;
        return;
    }

    if (!uiManager.getCompany().getCompanyClientManager().has(option)) {
        std::cout << std::endl << "Something unexpected occurred, aborting..." << std::endl;
        ui_util::displayPlaceholder();
        return;
    }

    CompanyClient &company = *uiManager.getCompany().getCompanyClientManager().getCompany(option);

    getCompanyClient(company);

    ui_util::displayPlaceholder();
}

void CompaniesClientInformationUI::getCompanyClient(CompanyClient &company) const {
    std::cout << std::endl << "Company information:" << std::endl;
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
