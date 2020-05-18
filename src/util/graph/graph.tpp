#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "../string/util_string.h"
#include "../../model/location/location.h"
#include "../../exception/invalid_file_exception.h"
#include "../../exception/invalid_vertex_exception.h"

template<class T>
void Graph<T>::add(const T &content) {
    Vertex<T> vertex(content);
    vertices.push_back(vertex);
}

template<class T>
std::shared_ptr<Edge<T>> Graph<T>::add(const T &source, const T &dest, double w) {
    Vertex<Location> &s = getVertex(source);
    Vertex<Location> &d = getVertex(dest);

    return s.add(&d, w);
}

template<class T>
Vertex<T> &Graph<T>::getVertex(const T &content) {
    Vertex<T> tmp(content);

    auto it = std::find(vertices.begin(), vertices.end(), tmp);
    if (it == vertices.end())
        throw InvalidVertexException();

    return *it;
}

template<class T>
long Graph<T>::verticesCount() const {
    return this->vertices.size();
}

template<class T>
const std::vector<Vertex<T>> &Graph<T>::getVertices() const {
    return this->vertices;
}