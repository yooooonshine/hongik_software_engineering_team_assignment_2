#pragma once

#include <string>

class Login;
class User;

class Logout {
private:
    Login* login;

public:
    Logout(Login* login);

    std::string logout();
};
