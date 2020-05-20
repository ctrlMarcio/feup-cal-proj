#ifndef FEUP_CAL_PROJ_PICKUP_POINTS_UI_H
#define FEUP_CAL_PROJ_PICKUP_POINTS_UI_H

#include <vector>
#include "../../ui/ui_manager.h"

class PickUpPoints : public UI {
public:
    explicit PickUpPoints(UIManager &uiManager);

    void run() override;

    void addPickUpPoint();

    void removePickUpPoint();

    void viewPickUpPoint();

private:
    UIManager &uiManager;

    std::vector<ui_util::Option> options;
};

#endif //FEUP_CAL_PROJ_PICKUP_POINTS_UI_H
