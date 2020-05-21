#include "company_client_information.h"

CompanyClientInformation::CompanyClientInformation(UIManager &uiManager) : uiManager(uiManager) {}

void CompanyClientInformation::getCompanyClient()
{
    CompanyClient *companyClient = uiManager.getCompany().getCompanyClientManager().getCompany(uiManager.getCurrentSession().getUser().getEmail());
    std::cout << "Company Name: " << companyClient->getName() << endl;
    std::cout << "Company Representative: " << companyClient->getRepresentative().getName() << " (" << companyClient->getRepresentative().getEmail() <<")" << endl;
    std::cout << "Company Headquarters Location: " << companyClient->getHeadquarters().getCity() << " - " << companyClient->getHeadquarters().getX() << " / " << companyClient->getHeadquarters().getY() << endl;
    std::cout << "Number of vehicles assigned: " << companyClient->getVehicleNumber() << endl ;
    return;
}

void CompanyClientInformation::run() {
    std::cout << uiManager.getHeader();

    std::cout << "Company information: "<< endl << endl;
    getCompanyClient();
    options.push_back(ui_util::make_option(0, "Exit"));

    int option = ui_util::getOption(options);

    if (option != 0)
        run();
}