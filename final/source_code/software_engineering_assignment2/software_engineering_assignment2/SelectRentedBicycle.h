#pragma once

#include <vector>
#include "Login.h"
#include "BicycleDetails.h"

class SelectRentedBicycle {
private:
    Login* login;

public:
    SelectRentedBicycle(Login* login);

    std::vector<BicycleDetails> searchRentedBicycle();
};