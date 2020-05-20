#ifndef FEUP_CAL_PROJ_MODIFY_COMPANY_VEHICLES_UI_H
#define FEUP_CAL_PROJ_MODIFY_COMPANY_VEHICLES_UI_H

#include <vector>
#include "../../ui/ui_manager.h"

class ModifyCompanyVehiclesUI : public UI {
public:
    explicit ModifyCompanyVehiclesUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;
};

#endif //FEUP_CAL_PROJ_MODIFY_COMPANY_VEHICLES_UI_H
