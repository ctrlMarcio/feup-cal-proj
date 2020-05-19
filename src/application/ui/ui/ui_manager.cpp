#include "ui_manager.h"

UIManager::UIManager(AuthUserManager &authUserManager, CurrentSession &currentSession, Company &company)
        : authUserManager(authUserManager), currentSession(currentSession), company(company) {}

Company &UIManager::getCompany() const {
    return company;
}

CurrentSession &UIManager::getCurrentSession() const {
    return currentSession;
}

AuthUserManager &UIManager::getAuthUserManager() const {
    return authUserManager;
}

void UIManager::set(UI *ui) {
    std::cout << std::endl << company.getName() << TAB << TAB << TAB << TAB << TAB << TAB << TAB
              << ui_util::getCurrentDate()
              << std::endl;
    ui->run();
    free(ui);
}
