#ifndef FEUP_CAL_PROJ_COMPANY_H
#define FEUP_CAL_PROJ_COMPANY_H

#include <string>

using namespace std;

class Company {
private:
    string name;

public:
    explicit Company(string name);

    string getName() const;
};


#endif //FEUP_CAL_PROJ_COMPANY_H
