#pragma once

#include <string>
#include "User.h"
#include "UserManager.h"

class Login {
private:
    User* loginUser;
    UserManager* userManager;

public:
    Login(UserManager* userManager);

    User* login(const std::string& id, const std::string& password);
    void setLoginUser(User* user);
    User* getLoginUser();
};