#include "company_client_graph_ui.h"
#include "../../../../util/view_graph/view_graph_viewer.h"

CompanyClientGraphUI::CompanyClientGraphUI(const UIManager &uiManager) : uiManager(uiManager) {}

void CompanyClientGraphUI::run()
{
    GraphViewer *gv = view_GraphViewer::buildGraphView(uiManager.getCompany().getGraph(), 5);

    CompanyClient *companyClient = uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());

    const std::string COLORS[] = {BLUE,ORANGE,RED,GREEN,GRAY,YELLOW};

    for (int i = 0; i < companyClient->getRoutes().second.size(); ++i) {
        std::string color = COLORS[i%6];
        for (const Location &location : companyClient->getRoutes().second[i].getLocations())
        {
            gv->setVertexColor(location.getId(), color);
            gv->setVertexSize(location.getId(),20);
        }
    }
    int count=100000;
    for(int i=0;i<companyClient->getRoutes().first.size();i++)
    {
        std::string color = COLORS[i%6];
        const Path<Location> &path = *std::next(companyClient->getRoutes().first.begin(),i);
        for (int j = 0; j < path.getPath().size()-1; ++j) {
            auto first = std::next(path.getPath().begin(),j);
            auto second = std::next(path.getPath().begin(),j+1);
            gv->addEdge(count,(*first).get().getId(),(*second).get().getId(),EdgeType::DIRECTED);
            gv->setEdgeColor(count++,color);
        }
    }
    gv->rearrange();
}