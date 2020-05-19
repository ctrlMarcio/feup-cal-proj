#ifndef FEUP_CAL_PROJ_LOGIN_UI_H
#define FEUP_CAL_PROJ_LOGIN_UI_H

#include "../ui/ui_manager.h"

class LoginUI : public UI {
public:
    explicit LoginUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;
};

#endif //FEUP_CAL_PROJ_LOGIN_UI_H
