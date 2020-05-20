#ifndef FEUP_CAL_PROJ_TRIO_H
#define FEUP_CAL_PROJ_TRIO_H

#include <list>
#include "../graph/vertex.h"

template<class T>
class Trio {
public:
    explicit Trio(const Vertex<T> &vertex);

    Trio(const Trio<T> &source, const Edge<T> &edge);

    const Vertex<T> &getVertex() const;

    std::list<Vertex<T>> &getPath();

    double getPathCost() const;

    bool operator<(const Trio &rhs) const;

    bool operator>(const Trio &rhs) const;

    bool operator<=(const Trio &rhs) const;

    bool operator>=(const Trio &rhs) const;

private:
    Vertex<T> vertex;

    std::list<Vertex<T>> path;

    double pathCost;
};

#include "trio.tpp"

#endif //FEUP_CAL_PROJ_TRIO_H
