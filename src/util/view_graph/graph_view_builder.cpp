#include "graph_view_builder.h"

GraphViewBuilder::GraphViewBuilder(const Graph<Location> &graph, const int nodeSize) :
        graph(graph), nodeSize(nodeSize), edgeCount(0) {}

GraphViewer *GraphViewBuilder::build() {
    GraphViewer *gv = new GraphViewer(720, 720, false);
    gv->createWindow(720, 720);
    gv->defineVertexColor("pink");
    gv->defineVertexSize(nodeSize);
    gv->defineEdgeColor("black");
    gv->defineEdgeCurved(false);

    for (const auto &vertex : graph.getVertices()) {
        gv->addNode(vertex.second.get().getId(), vertex.second.get().getX(), vertex.second.get().getY());
        gv->setVertexLabel(vertex.second.get().getId(), std::to_string(vertex.second.get().getId()));
        gv->setVertexSize(vertex.second.get().getId(), nodeSize);
    }

    int edgeId = 0;
    for (const auto &vertex : graph.getVertices())
        for (const auto &edge : vertex.second.getOutgoing())
            gv->addEdge(edgeId++, vertex.second.get().getId(), edge->getDestination()->get().getId(), EdgeType::DIRECTED);

    edgeCount = edgeId - 1;
    gv->rearrange();
    return gv;
}

int GraphViewBuilder::getEdgeCount() const {
    return edgeCount;
}
