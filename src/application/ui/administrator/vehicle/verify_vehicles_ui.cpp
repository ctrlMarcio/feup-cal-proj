#include "verify_vehicles_ui.h"

VerifyVehiclesUI::VerifyVehiclesUI(UIManager &uiManager) : uiManager(uiManager) {}

void VerifyVehiclesUI::run() {
	std::cout << uiManager.getHeader();

	long currentVehicles = uiManager.getCompany().getVehicleNumber();
    long usedVehicles = uiManager.getCompany().getUsedVehiclesNumber();

    std::cout << "Current vehicles: " << currentVehicles << std::endl;
    std::cout << "Vehicles in use:  " << usedVehicles << std::endl;

    std::cout << std::endl;

	while (!modifyVehicles(usedVehicles));
}

bool VerifyVehiclesUI::modifyVehicles(long usedVehicles) {
    unsigned long vehicles = ui_util::getUnsigned("New number of vehicles (0 to return): ");

    if (vehicles == 0) {
        std::cout << "Returning..." << std::endl;
        return true;
    } else if (vehicles < usedVehicles) {
        std::cout << "There are " << usedVehicles << " vehicles already in use, try again..." << std::endl << std::endl;
        return false;
    } else {
        if (this->uiManager.getCompany().setVehicleNumber(vehicles)) {
            std::cout << "Vehicle number updated to " << vehicles << "!" << std::endl;
            return true;
        } else {
            std::cout << "Unexpected error, value not updated, try again..." << std::endl << std::endl;
            return false;
        }
    }
}
