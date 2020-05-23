#ifndef FEUP_CAL_PROJ_PICKUP_POINT_UI_H
#define FEUP_CAL_PROJ_PICKUP_POINT_UI_H

#include <vector>
#include "../../ui/ui_manager.h"

class PickUpPointUI : public UI {
public:
    explicit PickUpPointUI(UIManager &uiManager);

    void run() override;

    void addPickUpPoint();

    void removePickUpPoint();

    void viewPickUpPoint();

    long getLocation();

    long getPickupPoint(const CompanyClient &companyClient);

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;
};

#endif //FEUP_CAL_PROJ_PICKUP_POINT_UI_H
