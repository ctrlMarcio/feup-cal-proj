#include "application/ui/ui/ui_manager.h"
#include "application/bootstrap/bootstrap.h"
#include "application/ui/home/home_ui.h"
#include "util/algorithm/algorithm.h"
#include "util/gmaps/google_map.h"

int main() {
    AuthUserManager userManager;
    CurrentSession session(userManager);

    Bootstrap bs("../../resources/Porto");

    Company company = bs.buildCompany("BosHBus", 1, 4);

    Administrator administrator("lola", "a");
    CompanyRepresentative companyRepresentative("lol", "b");

    CompanyClient companyClient("ai limão", companyRepresentative, *company.getLocationManager().get(35));
    companyClient.setVehicleNumber(4);

    srand(NULL);
    for (int i = 0; i < 15; ++i){
        int lol = rand() % 106;
        companyClient.addPickupPoint(*company.getLocationManager().get(lol));
    }

    std::list<Path<Location>> paths = algorithm::getPaths(companyClient, company);

    GoogleMap gmap(paths, company.getGarageLocation(), companyClient.getHeadquarters(),
                   companyClient.getPickupPoints());

    company.getCompanyClientManager().add(companyClient);
    company.getAdministratorManager().add(administrator);

    userManager.add(AuthUser("a", "a", AuthUser::ADMINISTRATOR));
    userManager.add(AuthUser("b", "b", AuthUser::COMPANY_REPRESENTATIVE));

    UIManager uiManager(userManager, session, company);

    uiManager.set(new HomeUI(uiManager));

    return EXIT_SUCCESS;
}
