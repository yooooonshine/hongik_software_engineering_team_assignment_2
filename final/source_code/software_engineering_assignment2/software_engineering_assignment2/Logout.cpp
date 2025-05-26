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
            return "�α��ε� ����ڰ� �����ϴ�.";
        }

        login->setLoginUser(nullptr);

        return user->getId();
    }
};