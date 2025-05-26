#pragma once

#include <string>
#include "BicycleDetails.h"

class Login;
class BicycleManager;

class RentBicycle {
private:
    Login* login;
    BicycleManager* bicycleManager;

public:
    RentBicycle(Login* login, BicycleManager* bicycleManager);

    BicycleDetails rentBicycle(const std::string& bicycleId);
};