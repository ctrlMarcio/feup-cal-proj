#include "home_ui.h"
#include "../login/login_ui.h"

HomeUI::HomeUI(UIManager &uiManager) : uiManager(uiManager) {}

void HomeUI::run() {
    std::cout << std::endl;
    std::cout << "Welcome to the " << uiManager.getCompany().getName() << " terminal interface!" << std::endl;

    std::vector<ui_util::Option> options;
    options.push_back(ui_util::make_option(1, "Login"));
    options.push_back(ui_util::make_option(0, "Quit"));

    int option = ui_util::getOption(options);

    switch (option) {
        case 0:
            cout << std::endl << "See you later..." << std::endl;
            break;
        case 1:
            uiManager.set(new LoginUI(uiManager));
            break;
        default:
            break;
    }
}
