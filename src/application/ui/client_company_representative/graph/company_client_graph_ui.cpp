#include "company_client_graph_ui.h"
#include "../../../../util/view_graph/graph_view_builder.h"

CompanyClientGraphUI::CompanyClientGraphUI(const UIManager &uiManager, bool returning) : uiManager(uiManager), returning(returning) {}

void CompanyClientGraphUI::run() {
    cout << endl << "Loading graph..." << endl;
    buildGraph();
}

void CompanyClientGraphUI::buildGraph() {
    GraphViewBuilder builder(uiManager.getCompany().getGraph(), 5);
    GraphViewer *gv = builder.build();

    CompanyClient *companyClient = uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    const string COLOURS[] = {BLUE, ORANGE, RED, GREEN, GRAY, YELLOW};

    int colourIndex = 0;
    for (const auto & route : companyClient->getRoutes(returning)) {
        string colour = COLOURS[colourIndex++ % 6];

        for (const Location &location : route.getCluster().getLocations()) {
            gv->setVertexColor(location.getId(), colour);
            gv->setVertexSize(location.getId(), 20);
        }
    }

    int count = builder.getEdgeCount() + 1;
    for (int i = 0; i < companyClient->getRoutes(returning).size(); i++) {
        string color = COLOURS[i % 6];
        const Path<Location> &path = *next(companyClient->getRoutes(returning).begin(), i);
        for (int j = 0; j < path.getPath().size() - 1; ++j) {
            auto first = next(path.getPath().begin(), j);
            auto second = next(path.getPath().begin(), j + 1);
            gv->addEdge(count, (*first).get().getId(), (*second).get().getId(), EdgeType::DIRECTED);
            gv->setEdgeColor(count++, color);
        }
    }
    gv->rearrange();
}