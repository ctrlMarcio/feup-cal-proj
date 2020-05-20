#ifndef FEUP_CAL_PROJ_COMPANY_CLIENT_INFORMATION_H
#define FEUP_CAL_PROJ_COMPANY_CLIENT_INFORMATION_H


#include "../../ui/ui.h"
#include "../../ui/ui_manager.h"

class CompanyClientInformation : public UI {
public:
    explicit CompanyClientInformation(UIManager &uiManager);

    void run() override;

    void getCompanyClient();

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;
};


#endif //FEUP_CAL_PROJ_COMPANY_CLIENT_INFORMATION_H
