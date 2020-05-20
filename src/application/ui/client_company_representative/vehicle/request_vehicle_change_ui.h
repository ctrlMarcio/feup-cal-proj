#ifndef FEUP_CAL_PROJ_REQUEST_VEHICLE_CHANGE_UI_H
#define FEUP_CAL_PROJ_REQUEST_VEHICLE_CHANGE_UI_H


#include "../../ui/ui.h"
#include "../../ui/ui_manager.h"

class RequestVehicleChangeUI : public UI {
public:
    explicit RequestVehicleChangeUI(UIManager &uiManager);

    void run() override;

private:
    UIManager &uiManager;

    static void printCurrentVehicleNumber(long currentVehicleNumber);
};


#endif //FEUP_CAL_PROJ_REQUEST_VEHICLE_CHANGE_UI_H
