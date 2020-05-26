#include "application/ui/ui/ui_manager.h"
#include "application/bootstrap/bootstrap.h"
#include "application/ui/home/home_ui.h"
#include "util/algorithm/algorithm.h"

void initDemo(char *const *argv, bool demo, AuthUserManager &userManager, Company &company,
              const CompanyRepresentative &companyRepresentative);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <map-name> <company-garage-id> [optional <demo>]" << std::endl;
        return EXIT_FAILURE;
    }

    bool demo = argc == 4 && string(argv[3]) == "true";

    long companyGarage;

    try {
        companyGarage = stol(argv[2]);
    } catch (invalid_argument &e) {
        std::cout << "The company garage id must be a number!" << std::endl;
        return EXIT_FAILURE;
    }

    AuthUserManager userManager;
    CurrentSession session(userManager);

    Bootstrap bs("resources/" + string(argv[1]));

    Company company = bs.buildCompany("BosHBus", companyGarage, 10);

    Administrator administrator("adm", "adm");
    CompanyRepresentative companyRepresentative("cpn", "cpn");

    initDemo(argv, demo, userManager, company, companyRepresentative);

    company.getAdministratorManager().add(administrator);
    userManager.add(AuthUser("adm", "adm", AuthUser::ADMINISTRATOR));

    UIManager uiManager(userManager, session, company);
    uiManager.set(new HomeUI(uiManager));

    return EXIT_SUCCESS;
}

void initDemo(char *const *argv, bool demo, AuthUserManager &userManager, Company &company,
              const CompanyRepresentative &companyRepresentative) {
    if (demo) {
        if (string(argv[1]) == "Porto_strong") {
            CompanyClient companyClient("cpn1", companyRepresentative, *company.getLocationManager().get(46604));
            companyClient.setVehicleNumber(5);

            companyClient.addPickupPoint(*company.getLocationManager().get(1665));
            companyClient.addPickupPoint(*company.getLocationManager().get(28490));
            companyClient.addPickupPoint(*company.getLocationManager().get(1879));
            companyClient.addPickupPoint(*company.getLocationManager().get(2007));
            companyClient.addPickupPoint(*company.getLocationManager().get(2126));
            companyClient.addPickupPoint(*company.getLocationManager().get(28994));
            companyClient.addPickupPoint(*company.getLocationManager().get(2441));
            companyClient.addPickupPoint(*company.getLocationManager().get(2641));

            company.getCompanyClientManager().add(companyClient);
        } else if (string(argv[1]) == "Porto") {
            CompanyClient companyClient("cpn1", companyRepresentative, *company.getLocationManager().get(35));
            companyClient.setVehicleNumber(3);

            companyClient.addPickupPoint(*company.getLocationManager().get(7));
            companyClient.addPickupPoint(*company.getLocationManager().get(9));
            companyClient.addPickupPoint(*company.getLocationManager().get(85));
            companyClient.addPickupPoint(*company.getLocationManager().get(28));
            companyClient.addPickupPoint(*company.getLocationManager().get(72));
            companyClient.addPickupPoint(*company.getLocationManager().get(84));

            company.getCompanyClientManager().add(companyClient);
        }

        userManager.add(AuthUser("cpn", "cpn", AuthUser::COMPANY_REPRESENTATIVE));
    }
}
