#ifndef FEUP_CAL_PROJ_REGISTER_COMPANY_UI_H
#define FEUP_CAL_PROJ_REGISTER_COMPANY_UI_H

#include "../../ui/ui_manager.h"

class RegisterCompanyUI : public UI {
public:
    explicit RegisterCompanyUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;

    std::string getEmail();

    long getHeadquarters();

};

#endif //FEUP_CAL_PROJ_REGISTER_COMPANY_UI_H
