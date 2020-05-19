#ifndef FEUP_CAL_PROJ_UI_MANAGER_H
#define FEUP_CAL_PROJ_UI_MANAGER_H

#include "ui.h"
#include "../../../auth/user/auth_user_manager.h"
#include "../../../model/company/company.h"
#include "../../../auth/session/current_session.h"
#include "../../../util/string/ui_util.h"

class UIManager {
public:
    UIManager(AuthUserManager &authUserManager, CurrentSession &currentSession, Company &company);

    Company &getCompany() const;

    CurrentSession &getCurrentSession() const;

    AuthUserManager &getAuthUserManager() const;

    void set(UI *ui);

private:
    Company &company;

    CurrentSession &currentSession;

    AuthUserManager &authUserManager;

};

#endif //FEUP_CAL_PROJ_UI_MANAGER_H
