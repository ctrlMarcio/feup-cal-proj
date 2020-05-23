#include "view_world_graph_ui.h"
#include "../../../../../lib/graphviewer.h"
#include "../../../../util/view_graph/view_graph_viewer.h"

ViewWorldGraphUI::ViewWorldGraphUI(UIManager &uiManager) : uiManager(uiManager) {}

void ViewWorldGraphUI::run() {
    std::cout << std::endl << "Loading..." << std::endl;
    buildGraph();
}

void ViewWorldGraphUI::buildGraph() const {// creates the graph viewer
    view_GraphViewer::buildGraphView(uiManager.getCompany().getGraph());
}
