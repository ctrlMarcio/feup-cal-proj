#include <iostream>
#include "application/bootstrap/bootstrap.h"
#include "model/company/company.h"

int main() {
    // test
    Bootstrap bs("../../PortugalMaps");

    Company company = bs.buildCompany("boshhhhhhhh", 90379359, 2);
    Location tmp(90379359, "", 0, 0);
    Vertex<Location> v = company.getGraph().getVertex(tmp);

    printf("%f\n", v.get().getX());
    std::cout << v.get().getY() << endl;
    std::cout << v.get().getLatitude() << endl;
    std::cout << v.get().getLongitude() << endl;

    return EXIT_SUCCESS;
}
