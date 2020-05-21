#ifndef FEUP_CAL_PROJ_COMPANY_INFORMATION_UI_H
#define FEUP_CAL_PROJ_COMPANY_INFORMATION_UI_H


#include "../../ui/ui_manager.h"

class CompanyInformationUI : public UI {
public:
    explicit CompanyInformationUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;
};


#endif //FEUP_CAL_PROJ_COMPANY_INFORMATION_UI_H
