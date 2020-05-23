#ifndef FEUP_CAL_PROJ_GRAPH_VIEW_BUILDER_H
#define FEUP_CAL_PROJ_GRAPH_VIEW_BUILDER_H


#include "graphviewer.h"
#include "../../model/location/location.h"
#include "../graph/graph.h"

class GraphViewBuilder {
public:
    explicit GraphViewBuilder(const Graph<Location> &graph, const int nodeSize = 20);

    GraphViewer *build();

    int getEdgeCount() const;

private:
    const Graph<Location> &graph;

    const int nodeSize;

    int edgeCount;
};


#endif //FEUP_CAL_PROJ_GRAPH_VIEW_BUILDER_H
