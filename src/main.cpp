#include <iostream>
#include "application/bootstrap/bootstrap.h"
#include "model/company/company.h"

int main() {
    // test
    Bootstrap bs("../../PortugalMaps");

    Company company = bs.buildCompany("boshhhhhhhh", 90379359, 2);
    Location tmp(26018641, "", 0, 0);
    auto ptr = company.getGraph().findVertex(tmp);

    std::cout << ptr->getInfo().getCity() << endl;

    for (auto vertex : company.getGraph().getVertexSet()) // TODO marcio proper destructor
        delete vertex.pointer;

    return EXIT_SUCCESS;
}
