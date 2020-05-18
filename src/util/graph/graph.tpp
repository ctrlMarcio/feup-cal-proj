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
#include "mutable_priority_queue.h"

template<class T>
bool Graph<T>::add(const T &content) {
    if (has(content)) return false;
    Vertex<T> vertex(content);
    vertices.push_back(vertex);
    return true;
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

template<class T>
bool Graph<T>::has(const T &content) const {
    return std::find_if(vertices.begin(), vertices.end(), [&content](const Vertex<T> &vertex) {
        return vertex.get() == content;
    }) != vertices.end();
}

template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
    for(auto v : getVertices()) {
        v.dist = INF;
        v.path = nullptr;
    }
    Vertex<T> *s = &getVertex(origin);
    s->dist = 0;
    return s;
}

template<class T>
inline bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
    if (v->dist + weight < w->dist) {
        w->dist = v->dist + weight;
        w->path = v;
        return true;
    }
    else
        return false;
}

template<class T>
void Graph<T>::dijkstra(const T &origin) {
    auto s = initSingleSource(origin);
    MutablePriorityQueue<Vertex<T>> q;
    q.insert(s);
    while( ! q.empty() ) {
        auto v = q.extractMin();
        for(auto e : v->getOutgoing()) {
            auto oldDist = e->getDestination()->dist;
            if (relax(v, e->getDestination(), e->getWeight())) {
                if (oldDist == INF)
                    q.insert(e->getDestination());
                else
                    q.decreaseKey(e->getDestination());
            }
        }
    }
}