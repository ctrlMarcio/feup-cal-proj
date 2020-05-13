#include <iostream>
#include "application/bootstrap/bootstrap.h"
#include "model/company/company.h"

int main() {
    // test
    Bootstrap bs("../../PortugalMaps");

    Company company = bs.buildCompany("boshhhhhhhh", 90379359, 2);
    Location tmp(25449719, "", 0, 0);
    auto ptr = company.getGraph().findVertex(tmp);

    printf("%f\n", ptr->getInfo().getX());
    std::cout << ptr->getInfo().getY() << endl;
    std::cout << ptr->getInfo().getLatitude() << endl;
    std::cout << ptr->getInfo().getLongitude() << endl;

    return EXIT_SUCCESS;
}
