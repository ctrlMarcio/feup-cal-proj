#ifndef FEUP_CAL_PROJ_VERIFY_VEHICLES_UI_H
#define FEUP_CAL_PROJ_VERIFY_VEHICLES_UI_H


#include "../../ui/ui.h"
#include "../../ui/ui_manager.h"

class VerifyVehiclesUI : public UI {
public:
	explicit VerifyVehiclesUI(UIManager &uiManager);

	void run() override;

private:
	UIManager &uiManager;

	bool modifyVehicles(long usedVehicles);
};


#endif //FEUP_CAL_PROJ_VERIFY_VEHICLES_UI_H
