#include "view_paths_ui.h"
#include "../../../../util/gmaps/google_map.h"

ViewPathsUI::ViewPathsUI(UIManager &uiManager) : uiManager(uiManager) {
    options.push_back(ui_util::make_option(1, "View using Google Maps Javascript API"));
    options.push_back(ui_util::make_option(2, "View using GraphViewer"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Return"));
}

void ViewPathsUI::run() {
    CompanyClient &companyClient = *uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    std::cout << uiManager.getHeader();
    std::cout << "Select a preview interface from the list..." << std::endl;

    int option = ui_util::getOption(options);

    switch (option) {
        case 0:
            cout << std::endl << "Returning..." << std::endl;
            break;
        case 1:
            showGoogleMaps(companyClient);
            ui_util::displayPlaceholder();
            break;
        case 2:
            break;
        default:
            break;
    }
}

void ViewPathsUI::calculatePaths(CompanyClient &company) {
    if (company.isCalculated()) return;

    uiManager.getCompany().getPaths(company);
}

void ViewPathsUI::showGoogleMaps(CompanyClient &client) {
    calculatePaths(client);

    GoogleMap gMap(client.getRoutes().first, uiManager.getCompany().getGarageLocation(), client.getHeadquarters(),
                   client.getRoutes().second);

    gMap.show();

    std::cout << std::endl << "An html file was created in the root folder!" << std::endl;
}
