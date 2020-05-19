#include "modify_company_vehicles_ui.h"

ModifyCompanyVehiclesUI::ModifyCompanyVehiclesUI(UIManager &uiManager) : uiManager(uiManager) {
    for (const CompanyClient &companyClient : uiManager.getCompany().getCompanyClientManager().getCompanies())
        options.push_back(ui_util::make_option(companyClient.getUUID(),
                                               companyClient.getName() + ", " +
                                               std::to_string(companyClient.getVehicleNumber()) +
                                               " vehicle(s) in use"));

    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Quit"));
}

void ModifyCompanyVehiclesUI::run() {
    std::cout << uiManager.getHeader();
    if (options.empty()) {
        std::cout << "There are no companies registered!" << std::endl;
        return;
    }

    std::cout << "There are currently "
              << uiManager.getCompany().getVehicleNumber() - uiManager.getCompany().getUsedVehiclesNumber()
              << " vehicle(s) available." << std::endl << "Please select a company from the list..." << std::endl;

    int option = ui_util::getOption(options);

    if (option == 0) return;

    std::cout << std::endl;

    CompanyClient &companyClient = *(uiManager.getCompany().getCompanyClientManager().getCompany(option));

    long number = ui_util::getLong("Enter the new vehicle number: ");

    if (number <= 0) {
        std::cout
                << std::endl
                << "Could not update the vehicle number! The vehicle number cannot be 0 or less..."
                << std::endl;
        return;
    }

    if (uiManager.getCompany().setVehicleNumber(companyClient, number)) {
        std::cout << std::endl << "Vehicle number updated to " << number << "!" << std::endl;
        return;
    } else {
        std::cout
                << std::endl
                << "Could not update the vehicle number! The vehicle number exceeds the number of vehicles available..."
                << std::endl;
        return;
    }
}
