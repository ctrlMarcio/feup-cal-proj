#include "application/ui/ui/ui_manager.h"
#include "application/bootstrap/bootstrap.h"
#include "application/ui/home/home_ui.h"

int main() {
    AuthUserManager userManager;
    CurrentSession session(userManager);

    Bootstrap bs("../../resources/GridGraphs");

    Company company = bs.buildCompany("BosHBus", 0, 2);

    Administrator administrator("lola", "a");
    CompanyRepresentative companyRepresentative("lol", "b");

    CompanyClient companyClient("ai limão", companyRepresentative, company.getGraph().getVertices()[3].get());

    company.getCompanyClientManager().add(companyClient);
    company.getAdministratorManager().add(administrator);

    userManager.add(AuthUser("a", "a", AuthUser::ADMINISTRATOR));
    userManager.add(AuthUser("b", "b", AuthUser::COMPANY_REPRESENTATIVE));

    UIManager uiManager(userManager, session, company);

    uiManager.set(new HomeUI(uiManager));

    return EXIT_SUCCESS;
}
