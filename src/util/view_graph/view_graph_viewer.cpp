#include "view_graph_viewer.h"

GraphViewer * view_GraphViewer::buildGraphView(const Graph<Location> &graph, int nodeSize) {
    GraphViewer *gv = new GraphViewer(720, 720, false);
    gv->createWindow(720,720);
    gv->defineVertexColor("pink");
    gv->defineVertexSize(nodeSize);
    gv->defineEdgeColor("black");
    gv->defineEdgeCurved(false);

    for (const Vertex<Location> &vertex : graph.getVertices()) {
        gv->addNode(vertex.get().getId(), vertex.get().getX(), vertex.get().getY());
        gv->setVertexLabel(vertex.get().getId(), std::to_string(vertex.get().getId()));
        gv->setVertexSize(vertex.get().getId(),nodeSize);
    }

    int edgeId = 0;
    for (const Vertex<Location> &vertex : graph.getVertices())
        for (const auto &edge : vertex.getOutgoing())
            gv->addEdge(edgeId++, vertex.get().getId(), edge->getDestination()->get().getId(), EdgeType::DIRECTED);

    gv->rearrange();
    return gv;
}
