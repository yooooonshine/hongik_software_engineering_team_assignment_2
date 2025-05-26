#include <vector>
#include <string>
#include "Bicycle.h"

class BicycleManager {
private:
    std::vector<Bicycle> bicycles;

public:
    void addBicycle(const Bicycle& bicycle) {
        bicycles.push_back(bicycle);
    }

    std::vector<Bicycle> getAllBicycles() const {
        return bicycles;
    }

    Bicycle* findBicycleById(const std::string& id) {
        for (auto& bicycle : bicycles) {
            if (bicycle.getBicycleId() == id) {
                return &bicycle;
            }
        }
        return nullptr;
    }
};