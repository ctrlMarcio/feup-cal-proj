#include "request_vehicle_change_ui.h"

RequestVehicleChangeUI::RequestVehicleChangeUI(UIManager &uiManager) : uiManager(uiManager) {}

void RequestVehicleChangeUI::run() {
    std::cout << uiManager.getHeader();

    const CompanyClient &companyClient = *uiManager.getCompany().getCompanyClientManager().getCompany(
            uiManager.getCurrentSession().getUser().getEmail());
    long currentVehicleNumber = companyClient.getVehicleNumber();

    // prints the number of vehicles currently available
    printCurrentVehicleNumber(currentVehicleNumber);

    // asks for the new number of vehicles
    unsigned long vehicleNumber = ui_util::getUnsigned("New number of vehicles (0 to return): ");

    if (!vehicleNumber) {
        std::cout << "Returning..." << std::endl;
        return;
    }

    // sends the notification to the administrators
    uiManager.getCompany().getAdministratorManager().sendNotification(
            "Company " + companyClient.getName() + " would like to change their number of vehicles to " +
            std::to_string(vehicleNumber) + ".");

    std::cout << std::endl << "Request sent successfully!" << std::endl;
}

void RequestVehicleChangeUI::printCurrentVehicleNumber(long currentVehicleNumber) {
    string personOfTheVerbalTime = "are";  // xd
    string vehicleSpell = "vehicle";
    if (currentVehicleNumber == 1) {
        personOfTheVerbalTime = "is";
        vehicleSpell += "s";
    }
    cout << "There " << personOfTheVerbalTime << " currently " << currentVehicleNumber << " " << vehicleSpell
         << " available."
         << endl << endl;
}
