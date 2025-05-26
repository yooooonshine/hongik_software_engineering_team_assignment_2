#include "Logout.h"

class LogoutUI {
private:
    Logout* logoutController;

public:
    LogoutUI(Logout* logoutController) : logoutController(logoutController) {}

    std::string logout() {
        return logoutController->logout();
    }
};