#include "view_world_graph_ui.h"
#include <graphviewer.h>

ViewWorldGraphUI::ViewWorldGraphUI(UIManager &uiManager) : uiManager(uiManager) {}

void ViewWorldGraphUI::run() {
    std::cout << std::endl << "Loading..." << std::endl;
    buildGraph();
}

void ViewWorldGraphUI::buildGraph() const {// creates the graph viewer
    GraphViewer *gv = new GraphViewer(720, 720, false);
    gv->createWindow(720, 720);
    gv->defineVertexColor("pink");
    gv->defineEdgeColor("black");
    gv->defineEdgeCurved(false);

    for (const Vertex<Location> &vertex : uiManager.getCompany().getGraph().getVertices()) {
        gv->addNode(vertex.get().getId(), vertex.get().getX(), vertex.get().getY());
        gv->setVertexLabel(vertex.get().getId(), std::to_string(vertex.get().getId()));
    }

    int edgeId = 0;
    for (const Vertex<Location> &vertex : uiManager.getCompany().getGraph().getVertices())
        for (const auto &edge : vertex.getOutgoing())
            gv->addEdge(edgeId++, vertex.get().getId(), edge->getDestination()->get().getId(), EdgeType::DIRECTED);

    gv->rearrange();
}
