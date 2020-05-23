#ifndef FEUP_CAL_PROJ_VIEW_GRAPH_VIEWER_H
#define FEUP_CAL_PROJ_VIEW_GRAPH_VIEWER_H


#include "graphviewer.h"
#include "../../model/location/location.h"
#include "../graph/graph.h"

namespace view_GraphViewer {
    GraphViewer *buildGraphView(const Graph<Location> &graph, int nodeSize=20);
};


#endif //FEUP_CAL_PROJ_VIEW_GRAPH_VIEWER_H
