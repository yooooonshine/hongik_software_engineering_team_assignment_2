#pragma once

#include <string>

class BicycleManager;

class EnrollBicycle {
private:
    BicycleManager* bicycleManager;

public:
    EnrollBicycle(BicycleManager* manager);
    void enrollBicycle(const std::string& id, const std::string& name);
};