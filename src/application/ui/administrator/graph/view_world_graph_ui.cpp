#include "view_world_graph_ui.h"
#include "../../../../../lib/graphviewer.h"
#include "../../../../util/view_graph/graph_view_builder.h"

ViewWorldGraphUI::ViewWorldGraphUI(UIManager &uiManager) : uiManager(uiManager) {}

void ViewWorldGraphUI::run() {
    std::cout << std::endl << "Loading graph..." << std::endl;
    buildGraph();
}

void ViewWorldGraphUI::buildGraph() const {
    GraphViewBuilder builder(uiManager.getCompany().getGraph());
    builder.build();
}
