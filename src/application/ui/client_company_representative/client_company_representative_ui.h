#ifndef FEUP_CAL_PROJ_CLIENT_COMPANY_REPRESENTATIVE_UI_H
#define FEUP_CAL_PROJ_CLIENT_COMPANY_REPRESENTATIVE_UI_H

#include "../ui/ui_manager.h"
#include "pickup_point/pickup_point_ui.h"

class ClientCompanyRepresentativeUI : public UI {
public:
    explicit ClientCompanyRepresentativeUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;
};

#endif //FEUP_CAL_PROJ_CLIENT_COMPANY_REPRESENTATIVE_UI_H
