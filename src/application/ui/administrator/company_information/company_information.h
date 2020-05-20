#ifndef FEUP_CAL_PROJ_COMPANY_INFORMATION_H
#define FEUP_CAL_PROJ_COMPANY_INFORMATION_H


#include "../../ui/ui_manager.h"

class CompanyInformation : public UI{
public:
    explicit CompanyInformation(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;
};


#endif //FEUP_CAL_PROJ_COMPANY_INFORMATION_H
