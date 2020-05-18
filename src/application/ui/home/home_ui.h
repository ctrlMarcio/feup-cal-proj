#ifndef FEUP_CAL_PROJ_HOME_UI_H
#define FEUP_CAL_PROJ_HOME_UI_H

#include "../ui/ui.h"
#include "../ui/ui_manager.h"

class HomeUI : public UI {
public:
    explicit HomeUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;
};

#endif //FEUP_CAL_PROJ_HOME_UI_H
