#include "company_client_graph_ui.h"
#include "../../../../util/view_graph/graph_view_builder.h"

CompanyClientGraphUI::CompanyClientGraphUI(const UIManager &uiManager) : uiManager(uiManager) {}

void CompanyClientGraphUI::run() {
    cout << endl << "Loading graph..." << endl;
    buildGraph();
}

void CompanyClientGraphUI::buildGraph() {
    GraphViewBuilder builder(uiManager.getCompany().getGraph(), 5);
    GraphViewer *gv = builder.build();

    CompanyClient *companyClient = uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    const string COLORS[] = {BLUE, ORANGE, RED, GREEN, GRAY, YELLOW};

    for (int i = 0; i < companyClient->getRoutes().second.size(); ++i) {
        string color = COLORS[i % 6];
        for (const Location &location : companyClient->getRoutes().second[i].getLocations()) {
            gv->setVertexColor(location.getId(), color);
            gv->setVertexSize(location.getId(), 20);
        }
    }

    int count = builder.getEdgeCount() + 1;
    for (int i = 0; i < companyClient->getRoutes().first.size(); i++) {
        string color = COLORS[i % 6];
        const Path<Location> &path = *next(companyClient->getRoutes().first.begin(), i);
        for (int j = 0; j < path.getPath().size() - 1; ++j) {
            auto first = next(path.getPath().begin(), j);
            auto second = next(path.getPath().begin(), j + 1);
            gv->addEdge(count, (*first).get().getId(), (*second).get().getId(), EdgeType::DIRECTED);
            gv->setEdgeColor(count++, color);
        }
    }
    gv->rearrange();
}