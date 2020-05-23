#include "application/ui/ui/ui_manager.h"
#include "application/bootstrap/bootstrap.h"
#include "application/ui/home/home_ui.h"
#include "util/algorithm/algorithm.h"

int main() {
    AuthUserManager userManager;
    CurrentSession session(userManager);

    Bootstrap bs("resources/Porto");

    Company company = bs.buildCompany("BosHBus", 6, 4);

    Administrator administrator("lola", "a");
    CompanyRepresentative companyRepresentative("lol", "b");

    CompanyClient companyClient("ai limão", companyRepresentative, *company.getLocationManager().get(35));
    companyClient.setVehicleNumber(3);

    companyClient.addPickupPoint(*company.getLocationManager().get(91));
    companyClient.addPickupPoint(*company.getLocationManager().get(85));
    companyClient.addPickupPoint(*company.getLocationManager().get(13));
    companyClient.addPickupPoint(*company.getLocationManager().get(24));
    companyClient.addPickupPoint(*company.getLocationManager().get(49));
    companyClient.addPickupPoint(*company.getLocationManager().get(67));

    company.getCompanyClientManager().add(companyClient);
    company.getAdministratorManager().add(administrator);

    userManager.add(AuthUser("a", "a", AuthUser::ADMINISTRATOR));
    userManager.add(AuthUser("b", "b", AuthUser::COMPANY_REPRESENTATIVE));

    UIManager uiManager(userManager, session, company);

    uiManager.set(new HomeUI(uiManager));

    return EXIT_SUCCESS;
}
