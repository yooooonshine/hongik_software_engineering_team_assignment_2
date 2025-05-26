#pragma once

#include <vector>
#include "BicycleDetails.h"
#include "SelectRentedBicycle.h"

class SelectRentedBicycleUI {
private:
    SelectRentedBicycle* service;

public:
    SelectRentedBicycleUI(SelectRentedBicycle* service);

    std::vector<BicycleDetails> searchRentedBicycle();
};