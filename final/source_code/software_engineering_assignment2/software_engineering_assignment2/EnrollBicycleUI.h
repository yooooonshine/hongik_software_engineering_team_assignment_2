#pragma once

#include <string>

class EnrollBicycle;
class EnrollBicycleUI {
private:
    EnrollBicycle* enroolBicycleController;

public:
    EnrollBicycleUI(EnrollBicycle* enroolBicycleController);

    void enrollBicycle(const std::string& id, const std::string& name);
};