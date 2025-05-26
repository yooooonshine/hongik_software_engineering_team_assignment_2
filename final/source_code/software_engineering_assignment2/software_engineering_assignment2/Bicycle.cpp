#include "Bicycle.h"
#include "BicycleDetails.h"

Bicycle::Bicycle(const std::string& id, const std::string& name)
    : id(id), name(name), renterId("") {
}

BicycleDetails Bicycle::getBicycleDetails() const {
    return BicycleDetails(id, name, renterId);
}

bool Bicycle::isRented() const {
    return !renterId.empty();
}

void Bicycle::rentTo(const std::string& userId) {
    renterId = userId;
}

void Bicycle::returnBicycle() {
    renterId.clear();
}

std::string Bicycle::getBicycleId() const {
    return id;
}