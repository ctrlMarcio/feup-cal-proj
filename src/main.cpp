#include <iostream>
#include "application/ui/ui/ui_manager.h"
#include "auth/session/current_session.h"
#include "application/bootstrap/bootstrap.h"
#include "model/company/company.h"
#include "application/ui/home/home_ui.h"

int main() {
    AuthUserManager userManager;
    CurrentSession session(userManager);

    Bootstrap bs("../../maps");

    Company company = bs.buildCompany("BoshHBus", 90379359, 2);

    UIManager uiManager(userManager, session, company);

    uiManager.set(new HomeUI(uiManager));

    return EXIT_SUCCESS;
}
