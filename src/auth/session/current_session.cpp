#include "current_session.h"
#include "../../exception/invalid_login_exception.h"

CurrentSession::CurrentSession(AuthUserManager &auth_user_manager) : auth_user_manager(auth_user_manager) {}

AuthUser &CurrentSession::getUser() const {
    if (!logged) return *(new AuthUser("", "", ""));
    return current_user;
}

bool CurrentSession::login(const std::string &email, const std::string &password) {
    if (logged) return false;

    if (!auth_user_manager.has(email))
        throw InvalidLoginException("There is no user with that email");

    AuthUser user = *auth_user_manager.getUser(email);

    if (user.getPassword() != password)
        throw InvalidLoginException("The password is incorrect");

    current_user = user;

    logged = true;

    return true;
}

bool CurrentSession::login(const AuthUser &user) {
    return login(user.getEmail(), user.getPassword());
}

bool CurrentSession::logout() {
    if (!logged) return false;
    logged = false;
    return true;
}

bool CurrentSession::isLogged() const {
    return logged;
}
