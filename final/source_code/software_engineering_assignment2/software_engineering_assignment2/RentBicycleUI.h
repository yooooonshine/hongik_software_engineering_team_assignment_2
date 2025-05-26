#pragma once

#include <string>
#include "BicycleDetails.h"

class RentBicycle;

class RentBicycleUI {
private:
    RentBicycle* rentBicycleController;

public:
    RentBicycleUI(RentBicycle* rentBicycleController);

    BicycleDetails rentBicycle(const std::string& id);
};
