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

    int option = ui_util::getOption(options);

    switch (option) {
        case 0:
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
    options.clear();

    for (const Vertex<Location> &vertex : uiManager.getCompany().getGraph().getVertices())
        options.push_back(ui_util::make_option(vertex.get().getId(), vertex.get().getCity() +
                                                                     " (" + std::to_string(vertex.get().getX()) +
                                                                     "/" + std::to_string(vertex.get().getY())));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Quit"));

    if (options.empty()) {
        std::cout << "There are no locations available!" << std::endl;
    }

    std::cout << "Please select a location from the list..." << std::endl;
    int option = ui_util::getOption(options);
    if (option == 0) return;
    std::cout << std::endl;
    CompanyClient *companyClient = uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    for (const Vertex<Location> &vertex : uiManager.getCompany().getGraph().getVertices()) {
        if (vertex.get().getId() == option) {
            if (companyClient->addPickupPoint(vertex.get()))
                cout << "Pickup-point successfully added" << endl;
            else
                cout << "Could not add Pickup-point" << endl;
        }
    }

    std::vector<ui_util::Option> exit;
    exit.push_back(ui_util::make_option(0, "Continue"));
    option = ui_util::getOption(exit);
    if (option != 0)
        run();
}

void PickUpPointUI::removePickUpPoint() {
    std::cout << uiManager.getHeader();
    options.clear();
    CompanyClient *companyClient = uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    for (const Location &location : companyClient->getPickupPoints())
        options.push_back(ui_util::make_option(location.getId(), location.getCity() +
                                                                 " (" + std::to_string(location.getX()) +
                                                                 "/" + std::to_string(location.getY())));

    if (options.empty()) {
        std::cout << "There are no locations to be removed!" << std::endl;
        return;
    }

    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Quit"));
    std::cout << "Please select a location from the list..." << std::endl;
    int option = ui_util::getOption(options);
    if (option == 0) return;
    std::cout << std::endl;

    for (const Vertex<Location> &vertex : uiManager.getCompany().getGraph().getVertices()) {
        if (vertex.get().getId() == option) {
            if (companyClient->removePickupPoint(vertex.get()))
                cout << "Pickup-point successfully removed" << endl;
            else
                cout << "Could not remove Pickup-point" << endl;
        }
    }

    std::vector<ui_util::Option> exit;
    exit.push_back(ui_util::make_option(0, "Continue"));
    option = ui_util::getOption(exit);
    if (option != 0)
        run();
}

void PickUpPointUI::viewPickUpPoint() {
    std::cout << uiManager.getHeader();
    std::vector<Location> pickupPoints;
    std::cout << "Company pick-up points: " << std::endl << std::endl;
    const CompanyClient &companyClient = *uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    if (companyClient.getPickupPoints().size() == 0) {
        std::cout << "No pick-up points to display" << endl;
    } else {
        for (auto i: companyClient.getPickupPoints()) {
            std::cout << i.getId() << " - " << i.getCity() << " - " << i.getX() << " - " << i.getY() << i.getLatitude()
                      << " - " << i.getLongitude() << endl;
        }
    }

    std::vector<ui_util::Option> exit;
    exit.push_back(ui_util::make_option(0, "Exit"));
    int option = ui_util::getOption(exit);
    if (option != 0)
        run();
}
