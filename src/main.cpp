#include "application/ui/ui/ui_manager.h"
#include "application/bootstrap/bootstrap.h"
#include "application/ui/home/home_ui.h"
#include "util/algorithm/algorithm.h"

int main() {
    AuthUserManager userManager;
    CurrentSession session(userManager);

    Bootstrap bs("resources/Portugal");

    Company company = bs.buildCompany("BosHBus", 12366, 6);

    Administrator administrator("lola", "a");
    CompanyRepresentative companyRepresentative("lol", "b");

    CompanyClient companyClient("ai limão", companyRepresentative, *company.getLocationManager().get(46604));
    companyClient.setVehicleNumber(4);

    companyClient.addPickupPoint(*company.getLocationManager().get(28617));
    companyClient.addPickupPoint(*company.getLocationManager().get(8371));
    companyClient.addPickupPoint(*company.getLocationManager().get(28830));
    companyClient.addPickupPoint(*company.getLocationManager().get(32766));
    companyClient.addPickupPoint(*company.getLocationManager().get(4850));
    companyClient.addPickupPoint(*company.getLocationManager().get(49603));
    companyClient.addPickupPoint(*company.getLocationManager().get(23657));

    company.getCompanyClientManager().add(companyClient);
    company.getAdministratorManager().add(administrator);

    userManager.add(AuthUser("a", "a", AuthUser::ADMINISTRATOR));
    userManager.add(AuthUser("b", "b", AuthUser::COMPANY_REPRESENTATIVE));

    UIManager uiManager(userManager, session, company);

    uiManager.set(new HomeUI(uiManager));

    return EXIT_SUCCESS;
}
