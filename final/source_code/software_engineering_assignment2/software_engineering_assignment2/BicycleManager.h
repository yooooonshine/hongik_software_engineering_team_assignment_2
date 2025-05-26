#pragma once

#include <vector>
#include <string>
#include "Bicycle.h"

class BicycleManager {
private:
    std::vector<Bicycle> bicycles;

public:
    void addBicycle(const Bicycle& bicycle);
    std::vector<Bicycle> getAllBicycles() const;
    Bicycle* findBicycleById(const std::string& id);
};