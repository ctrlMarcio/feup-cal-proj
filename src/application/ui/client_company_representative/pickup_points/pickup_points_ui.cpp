#include "pickup_points_ui.h"

PickUpPoints::PickUpPoints(UIManager &uiManager) : uiManager(uiManager) {
    options.push_back(ui_util::make_option(1, "Add new pickup-point"));
    options.push_back(ui_util::make_option(2, "Remove pickup-point"));
    options.push_back(ui_util::make_option(3, "View pickup-points"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Quit"));
}

void PickUpPoints::run() {
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

void PickUpPoints::addPickUpPoint() {

}

void PickUpPoints::removePickUpPoint() {

    int id = ui_util::getInteger("Choose pickup-point id");

    //companyClient.removePickupPoint();
}

void PickUpPoints::viewPickUpPoint() {
    std::cout << uiManager.getHeader();
    std::vector<Location> pickupPoints;

    std::cout << "Company pickup-points: "<< endl << endl;

    for (auto companyClient : uiManager.getCompany().getCompanyClientManager().getCompanies())
    {
        if (companyClient.getRepresentative().getEmail()==uiManager.getCurrentSession().getUser().getEmail())
        {
            for (auto i: companyClient.getPickupPoints())
            {
                std::cout << i.getId() << " - " << i.getCity() << " - " << i.getX() << " - " << i.getY() << i.getLatitude() << " - " << i.getLongitude() << endl;
            }
        }
    }

    std::vector<ui_util::Option> exit;
    exit.push_back(ui_util::make_option(0, "Exit"));

    int option = ui_util::getOption(exit);

    if (option != 0)
        run();
}