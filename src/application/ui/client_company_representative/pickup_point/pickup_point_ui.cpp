#include "pickup_point_ui.h"

PickUpPointUI::PickUpPointUI(UIManager &uiManager) : uiManager(uiManager) {
    options.push_back(ui_util::make_option(1, "Add new pick-up point"));
    options.push_back(ui_util::make_option(2, "Remove pick-up point"));
    options.push_back(ui_util::make_option(3, "View pick-up points"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Return"));
}

void PickUpPointUI::run() {
    std::cout << uiManager.getHeader();

    std::cout << "Select an operation from the list..." << std::endl;

    int option = ui_util::getOption(options);

    switch (option) {
        case 0:
            std::cout << std::endl << "Returning..." << std::endl;
            ui_util::displayPlaceholder();
            return;
        case 1:
            addPickUpPoint();
            break;
        case 2:
            removePickUpPoint();
            break;
        case 3:
            viewPickUpPoint();
            break;
        default:
            break;
    }
}

void PickUpPointUI::addPickUpPoint() {
    std::cout << uiManager.getHeader();

    long locationId = getLocation();

    CompanyClient &companyClient = *uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    if (companyClient.addPickupPoint(*uiManager.getCompany().getLocationManager().get(locationId))) {
        std::cout << std::endl << "Pick-up point successfully added!" << std::endl;
        ui_util::displayPlaceholder();
    } else {
        std::cout << std::endl << "Something unexpected occurred, the pick-up point may already exist!" << std::endl;
        ui_util::displayPlaceholder();
    }
}

void PickUpPointUI::removePickUpPoint() {
    std::cout << uiManager.getHeader();
    CompanyClient &companyClient = *uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    if (companyClient.getPickupPoints().empty()) {
        std::cout << "There are no locations to be removed!" << std::endl;
        ui_util::displayPlaceholder();
        return;
    }

    long locationId = getPickupPoint(companyClient);

    if (companyClient.removePickupPoint(*uiManager.getCompany().getLocationManager().get(locationId))) {
        std::cout << std::endl << "Pick-up point successfully removed!" << std::endl;
        ui_util::displayPlaceholder();
    } else {
        std::cout << std::endl << "Something unexpected occurred, the pick-up point may not exist!" << std::endl;
        ui_util::displayPlaceholder();
    }
}

void PickUpPointUI::viewPickUpPoint() {
    std::cout << uiManager.getHeader();

    const CompanyClient &companyClient = *uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    if (companyClient.getPickupPoints().empty()) {
        std::cout << "There are no pick-up points registered!" << std::endl;
        ui_util::displayPlaceholder();
        return;
    }

    std::cout << "The list of pick-up points:" << std::endl;

    for (const Location &location : companyClient.getPickupPoints()) {
        std::cout << "\t- " << location.getId() << " at " << std::fixed << std::setprecision(2) << location.getX()
                  << ", "
                  << location.getY() << std::endl;
    }

    ui_util::displayPlaceholder();
}

long PickUpPointUI::getLocation() {
    long id = ui_util::getLong("Enter the pick-up point location ID (0 to view all): ");

    if (id == 0) {
        std::cout << std::endl << "The list of available locations:" << std::endl;

        for (const Location &location : uiManager.getCompany().getLocationManager().getLocations()) {
            std::cout << "\t- " << location.getId() << " at " << std::fixed << std::setprecision(2) << location.getX()
                      << ", "
                      << location.getY() << std::endl;
        }

        ui_util::displayPlaceholder();
        std::cout << std::endl;

        return getLocation();
    }

    if (!uiManager.getCompany().getLocationManager().has(id)) {
        std::cout
                << std::endl
                << "That location does not exist, try again..."
                << std::endl << std::endl;
        return getLocation();
    }

    return id;
}

long PickUpPointUI::getPickupPoint(const CompanyClient &companyClient) {
    long id = ui_util::getLong("Enter the pick-up point location ID (0 to view all): ");

    if (id == 0) {
        std::cout << std::endl << "The list of available locations:" << std::endl;

        for (const Location &location : companyClient.getPickupPoints()) {
            std::cout << "\t- " << location.getId() << " at " << std::fixed << std::setprecision(2) << location.getX()
                      << ", "
                      << location.getY() << std::endl;
        }

        ui_util::displayPlaceholder();
        std::cout << std::endl;

        return getPickupPoint(companyClient);
    }

    std::vector<Location> pickupPoints = companyClient.getPickupPoints();
    auto it = std::find_if(pickupPoints.begin(), pickupPoints.end(),
                           [&id](const Location &location) {
                               return id == location.getId();
                           });

    if (it == pickupPoints.end()) {
        std::cout
                << std::endl
                << "That location does not exist, try again..."
                << std::endl << std::endl;
        return getPickupPoint(companyClient);
    }

    return id;
}
