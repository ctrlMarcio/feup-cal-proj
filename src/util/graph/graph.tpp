#include <fstream>
#include <sstream>
#include <string>
#include "../string/util_string.h"
#include "../../model/location/location.h"

template<class T>
shared_ptr<Vertex<T>> Graph<T>::addVertex(const T &content) {
	auto v = findVertex(content);
	if (v != nullptr)
		return v;
	v = make_shared<Vertex<T>>(content);
	vertexSet.insert(v);
	return v;
}

template<class T>
shared_ptr<Vertex<T>> Graph<T>::findVertex(const T &content) const {
	for (auto v : vertexSet)
		if (v->getInfo() == content)
			return v;
	return nullptr;
}

template<class T>
set<shared_ptr<Vertex<T>>> Graph<T>::getVertexSet() const {
	return this->vertexSet;
}

template<class T>
shared_ptr<Edge<T>> Graph<T>::addEdge(const T &source, const T &dest, double w) {
	auto s = findVertex(source);
	auto d = findVertex(dest);
	if (s == nullptr || d == nullptr)
		return nullptr;
	else
		return s->addEdge(d, w);
}

template<>
void Graph<Location>::read(std::string &fileName, const std::string &city) {
    std::ifstream file(fileName);

    std::string line;
    std::getline(file, line); // reads the first, useless line

    while (std::getline(file, line)) {
        // example: (1284635486, 529773.8435496966, 4497624.344113585)

        // gets all elements
        std::vector<std::string> elements = util_string::split(line, DELIMITER);
        std::string idStr = elements[0];    // (1284635486
        std::string xStr = elements[1];     //  529773.8435496966
        std::string yStr = elements[2];     //  4497624.344113585)

        // removes the clutter in the strings
        idStr = idStr.substr(1, idStr.size() - 1);  // 1284635486
        yStr = yStr.substr(0, yStr.size() - 1);     // 4497624.344113585

        // casts to numbers
        long id = stol(idStr);
        double x = stod(xStr);
        double y = stod(yStr);

        // creates a location
        Location location(id, city, x, y);

        // add to the graph
        this->addVertex(location);
    }
}