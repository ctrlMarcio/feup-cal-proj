#include "home_ui.h"

HomeUI::HomeUI(UIManager &uiManager) : uiManager(uiManager) {}

void HomeUI::run() {
    cout << "Hello world from the " << uiManager.getCompany().getName() << " company!" << std::endl;
}
