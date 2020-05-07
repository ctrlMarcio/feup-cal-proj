#include <fstream>
#include <sstream>
#include <string>
#include "../string/util_string.h"
#include "../../model/location/location.h"
#include "graph.h"


template<class T>
shared_ptr<Vertex<T>> Graph<T>::addVertex(const T &content) {
    auto v = findVertex(content);
    if (v != nullptr)
        return v;
    v = make_shared<Vertex<T>>(content);
    vertexSet.push_back(v);
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
vector<shared_ptr<Vertex<T>>> Graph<T>::getVertexSet() const {
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
void Graph<Location>::readNodes(const std::string &fileName, const std::string &city) {
    std::ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        cerr << "Error opening " << fileName << endl;
        exit(1);
    }

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

    file.close();
}

template<>
bool Graph<Location>::readEdges(const string &fileName) {
    bool allOk = true;

    std::ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        cerr << "Error opening " << fileName << endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line); // reads the first, useless line

    while (std::getline(file, line)) {
        // example: (384994721, 384994722)

        // gets all elements
        std::vector<std::string> elements = util_string::split(line, DELIMITER);
        std::string srcStr = elements[0];   // (384994721
        std::string dstStr = elements[1];   //  384994722)

        // removes the clutter in the strings
        srcStr = srcStr.substr(1, srcStr.size() - 1);   // 384994721
        dstStr = dstStr.substr(0, dstStr.size() - 1);   // 384994722

        // casts to numbers
        long srcId = stol(srcStr);
        long dstId = stol(dstStr);

        // creates temporary locations to search for the real ones
        // location's "==" compares only the IDs
        Location tmpSrc(srcId, "", 0, 0);
        Location tmpDst(dstId, "", 0, 0);

        // gets the real locations
        auto src = findVertex(tmpSrc);
        auto dst = findVertex(tmpDst);

        // verifies if the locations exist
        if (!src || !dst) {
            allOk = false;
            continue;
        }

        // adds the edge
        this->addEdge(src->getInfo(), dst->getInfo(), 1);
    }

    file.close();

    return allOk;
}
