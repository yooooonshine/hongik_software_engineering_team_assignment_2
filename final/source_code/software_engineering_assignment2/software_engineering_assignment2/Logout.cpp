#include <iostream>
#include "Login.h"

class Logout {
private:
    Login* login;

public:
    Logout(Login* login) : login(login) {}

    std::string logout() {
        User* user = login->getLoginUser();

        if (user == nullptr) {
            return "로그인된 사용자가 없습니다.";
        }

        login->setLoginUser(nullptr);

        return user->getId();
    }
};