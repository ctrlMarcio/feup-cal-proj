#include "view_paths_ui.h"
#include "../../../../util/gmaps/google_map.h"
#include "../graph/company_client_graph_ui.h"

ViewPathsUI::ViewPathsUI(UIManager &uiManager) : uiManager(uiManager) {
    options.push_back(ui_util::make_option(1, "Compute with A* and NNF (approximate result, medium/long distances)"));
    options.push_back(ui_util::make_option(2, "Compute with Dijkstra (exact result, very short distances)"));
}

void ViewPathsUI::run() {
    CompanyClient &companyClient = *uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    std::cout << uiManager.getHeader();

    std::cout << "Select an algorithm to compute the paths..." << std::endl;

    int algorithm = ui_util::getOption(options);

    options.clear();

    options.push_back(ui_util::make_option(1, "Paths from garage to company headquarters"));
    options.push_back(ui_util::make_option(2, "Path from company headquarters to garage"));

    int pathType = ui_util::getOption(options);

    options.clear();

    options.push_back(ui_util::make_option(1, "View using Google Maps Javascript API"));
    options.push_back(ui_util::make_option(2, "View using GraphViewer"));
    options.push_back(ui_util::make_empty_line());
    options.push_back(ui_util::make_option(0, "Return"));

    std::cout << std::endl << "Select a preview interface from the list..." << std::endl;

    int option = ui_util::getOption(options);

    switch (option) {
        case 0:
            cout << std::endl << "Returning..." << std::endl;
            break;
        case 1:
            showGoogleMaps(companyClient, algorithm == 1, pathType == 2);
            ui_util::displayPlaceholder();
            break;
        case 2:
            showGraphView(companyClient, algorithm == 1, pathType == 2);
            ui_util::displayPlaceholder();
            break;
        default:
            break;
    }
}

void ViewPathsUI::showGoogleMaps(CompanyClient &client, bool approximate, bool returning) {
    uiManager.getCompany().calculatePaths(client, approximate, returning);

    GoogleMap gMap(client.getRoutes(returning), uiManager.getCompany().getGarageLocation(), client.getHeadquarters());

    gMap.show();

    std::cout << std::endl << "An html file was created in the root folder!" << std::endl;
}

void ViewPathsUI::showGraphView(CompanyClient &client, bool approximate, bool returning) {
    uiManager.getCompany().calculatePaths(client, approximate, returning);
    uiManager.set(new CompanyClientGraphUI(uiManager, returning));
}

