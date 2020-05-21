#ifndef FEUP_CAL_PROJ_COMPANIES_CLIENT_INFORMATION_UI_H
#define FEUP_CAL_PROJ_COMPANIES_CLIENT_INFORMATION_UI_H

#include "../../ui/ui_manager.h"

class CompaniesClientInformationUI : public UI {
public:
    explicit CompaniesClientInformationUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;

    void getCompanyClient(CompanyClient &company) const;
};

#endif //FEUP_CAL_PROJ_COMPANIES_CLIENT_INFORMATION_UI_H
