#include "register_company_ui.h"

RegisterCompanyUI::RegisterCompanyUI(UIManager &uiManager) : uiManager(uiManager) {}

void RegisterCompanyUI::run() {
    std::cout << uiManager.getHeader();

    if (uiManager.getCompany().getVehiclesLeft() == 0) {
        std::cout << "There are no vehicles available!" << std::endl;
        return;
    } else if (uiManager.getCompany().getLocationManager().getLocations().empty()) {
        std::cout << "There are no locations registered!" << std::endl;
        return;
    }

    std::cout << "Please fill the following form to register a company!" << std::endl << std::endl;

    std::string name = ui_util::getString("Enter the name of the company: ");
    std::string representative_name = ui_util::getString("Enter the name of the company representative: ");
    std::string representative_email = getEmail();
    std::string representative_password = ui_util::getString("Enter the password of the company representative: ");

    long locationId = getHeadquarters();

    const Location &loc = *(uiManager.getCompany().getLocationManager().get(locationId));

    // TODO: improve this method
    uiManager.getAuthUserManager().add(
            AuthUser(representative_email, representative_password, AuthUser::COMPANY_REPRESENTATIVE));
    uiManager.getCompany().getCompanyClientManager().add(
            CompanyClient(name, CompanyRepresentative(representative_name, representative_email), loc));
}

std::string RegisterCompanyUI::getEmail() {
    std::string email = ui_util::getString("Enter the email of the company representative: ");

    if (uiManager.getAuthUserManager().has(email)) {
        std::cout
                << std::endl
                << email << " is already in use, try again..."
                << std::endl << std::endl;
        return getEmail();
    }

    return email;
}

long RegisterCompanyUI::getHeadquarters() {
    long id = ui_util::getLong("Enter the company headquarters location ID (0 to view all): ");

    if (id == 0) {
        std::cout << std::endl << "The list of available locations:" << std::endl;

        for (const Location &location : uiManager.getCompany().getLocationManager().getLocations()) {
            std::cout << "\t- " << location.getId() << " at " << std::fixed << std::setprecision(2) << location.getX()
                      << ", "
                      << location.getY() << std::endl;
        }

        std::cout << std::endl;

        return getHeadquarters();
    }

    if (!uiManager.getCompany().getLocationManager().has(id)) {
        std::cout
                << std::endl
                << "That location does not exist, try again..."
                << std::endl << std::endl;
        return getHeadquarters();
    }

    return id;
}
