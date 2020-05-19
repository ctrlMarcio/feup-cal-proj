#ifndef FEUP_CAL_PROJ_MODIFY_VEHICLES_UI_H
#define FEUP_CAL_PROJ_MODIFY_VEHICLES_UI_H


#include "../../ui/ui.h"
#include "../../ui/ui_manager.h"

class ModifyVehiclesUI : public UI {
public:
	ModifyVehiclesUI(UIManager &uiManager);

	void run() override;

private:
	UIManager &uiManager;

	bool modifyVehicles(long usedVehicles);
};


#endif //FEUP_CAL_PROJ_MODIFY_VEHICLES_UI_H
