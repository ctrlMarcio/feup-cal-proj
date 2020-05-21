#ifndef FEUP_CAL_PROJ_COMPANIES_CLIENT_INFORMATION_UI_H
#define FEUP_CAL_PROJ_COMPANY_CLIENT_INFORMATION_UI_H


#include "../../ui/ui.h"
#include "../../ui/ui_manager.h"

class CompanyClientInformationUI : public UI {
public:
    explicit CompanyClientInformationUI(UIManager &uiManager);

    void run() override;

    void getCompanyClient();

private:
    UIManager &uiManager;
};

#endif //FEUP_CAL_PROJ_COMPANIES_CLIENT_INFORMATION_UI_H
