#include <iostream>

#include "util/graph/graph.h"

int main() {
	// TEST
	Graph<int> graph;
	graph.addVertex(1);
	graph.addVertex(2);
	graph.addEdge(1, 2, 3);

	auto a = graph.getVertexSet()[0];
	auto b = a->getAdj()[0];
	double w = b->getWeight();

    std::cout << "Hello, World! " << w << std::endl;
    return 0;
}
