#include "RentBicycle.h"
#include "BicycleDetails.h"

class RentBicycleUI {
private:
    RentBicycle* rentBicycleController;

public:
    RentBicycleUI(RentBicycle* rentBicycleController)
        : rentBicycleController(rentBicycleController) {
    }

    BicycleDetails rentBicycle(const std::string& id) {
        return rentBicycleController->rentBicycle(id);
    }
};