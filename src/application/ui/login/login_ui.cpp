#include "login_ui.h"
#include "../administrator/administrator_ui.h"

LoginUI::LoginUI(UIManager &uiManager) : uiManager(uiManager) {}

void LoginUI::run() {
    std::cout << uiManager.getHeader();

    std::pair<std::string, bool> emailPair = getEmail();
    if (!emailPair.second) return;

    std::pair<AuthUser, bool> passwordPair = getPassword(emailPair.first);
    if (!passwordPair.second) return;

    AuthUser authUser = passwordPair.first;
    if (!uiManager.getCurrentSession().login(authUser)) {
        std::cout << std::endl << "Something unexpected occurred, could not login this user!"
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    // Select role, redirect to specific UI
    if (authUser.getUserRole() == AuthUser::ADMINISTRATOR) {
        uiManager.set(new AdministratorUI(uiManager));
    } else if (authUser.getUserRole() == AuthUser::COMPANY_REPRESENTATIVE) {
        std::cout << std::endl << "THIS IS A COMPANY REPRESENTATIVE" << std::endl;
    } else
        std::cout << std::endl << "Something unexpected occurred!" << std::endl;
}

std::pair<std::string, bool> LoginUI::getEmail() {
    std::string email = ui_util::getString("Enter your email: ");

    if (!uiManager.getAuthUserManager().has(email)) {
        std::cout << std::endl << "That is not a valid email..." << std::endl;
        return std::make_pair(email, false);
    }

    return std::make_pair(email, true);
}

std::pair<AuthUser, bool> LoginUI::getPassword(const std::string &user) {
    AuthUser authUser = *uiManager.getAuthUserManager().get(user);

    std::string password = ui_util::getString("Enter your password: ");
    int tries = 3;

    while (password != authUser.getPassword() && tries > 1) {
        std::cout << std::endl << "Incorrect password, " << --tries << (tries == 1 ? " try" : " tries")
                  << " left..."
                  << std::endl << std::endl;

        password = ui_util::getString("Enter your password: ");
    }

    if (password != authUser.getPassword()) {
        std::cout << std::endl << "Incorrect passsword, try again later..." << std::endl << std::endl;

        return std::make_pair(authUser, false);
    }

    return std::make_pair(authUser, true);
}
