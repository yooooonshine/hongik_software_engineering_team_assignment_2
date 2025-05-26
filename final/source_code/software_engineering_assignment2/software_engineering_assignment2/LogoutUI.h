#pragma once

#include <string>

class Logout;

class LogoutUI {
private:
    Logout* logoutController;

public:
    LogoutUI(Logout* logoutController);

    std::string logout();
};