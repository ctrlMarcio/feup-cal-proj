#include "modify_vehicles_ui.h"

ModifyVehiclesUI::ModifyVehiclesUI(UIManager &uiManager) : uiManager(uiManager) {}

void ModifyVehiclesUI::run() {
	std::cout << uiManager.getHeader();

	long usedVehicles = uiManager.getCompany().getUsedVehiclesNumber();

	while (!modifyVehicles(usedVehicles));
}

bool ModifyVehiclesUI::modifyVehicles(long usedVehicles) {
	long vehicles = ui_util::getLong("New number of vehicles (-1 to return): ");

	if (vehicles == -1) {
		std::cout << "Returning..." << std::endl;
		return true;
	} else if (vehicles < -1) {
		std::cout << vehicles << " is an invalid vehicle number, try again..." << std::endl << std::endl;
		return false;
	} else if (vehicles < usedVehicles) {
		std::cout << "There are " << usedVehicles << " vehicles already in use, try again..." << std::endl << std::endl;
		return false;
	} else {
		if (this->uiManager.getCompany().updateVehicleNumber(vehicles)) {
			std::cout << "Updated!" << std::endl;
			return true;
		} else {
			std::cout << "Unexpected error, value not updated, try again..." << std::endl << std::endl;
			return false;
		}
	}
}
