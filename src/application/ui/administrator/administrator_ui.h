#ifndef FEUP_CAL_PROJ_ADMINISTRATOR_UI_H
#define FEUP_CAL_PROJ_ADMINISTRATOR_UI_H

#include "../ui/ui_manager.h"

class AdministratorUI : public UI {
public:
    explicit AdministratorUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;
};

#endif //FEUP_CAL_PROJ_ADMINISTRATOR_UI_H
