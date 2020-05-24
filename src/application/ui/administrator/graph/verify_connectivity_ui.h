#ifndef FEUP_CAL_PROJ_VERIFY_CONNECTIVITY_UI_H
#define FEUP_CAL_PROJ_VERIFY_CONNECTIVITY_UI_H


#include "../../ui/ui.h"
#include "../../ui/ui_manager.h"

class VerifyConnectivityUI : public UI {
public:
    explicit VerifyConnectivityUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;
};


#endif //FEUP_CAL_PROJ_VERIFY_CONNECTIVITY_UI_H
