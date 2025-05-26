#include "SelectRentedBicycle.h"

class SelectRentedBicycleUI {
private:
    SelectRentedBicycle* service;

public:
    SelectRentedBicycleUI(SelectRentedBicycle* service) : service(service) {}

    std::vector<BicycleDetails> searchRentedBicycle() {
        return service->searchRentedBicycle();
    }
};