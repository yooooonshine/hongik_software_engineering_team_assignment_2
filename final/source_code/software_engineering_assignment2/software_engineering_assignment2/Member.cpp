#include "Member.h"
#include <iostream>

Member::Member(const std::string& id, const std::string& password, std::string phoneNumber)
    : User(id, password, phoneNumber) {}

std::vector<Bicycle> Member::listBicycles() const {
    return bicycles;
}

void Member::rent(Bicycle& bicycle) {
    if (bicycle.isRented()) {
        std::cout << "Bicycle is already rented.\n";
    }

    bicycle.rentTo(id);
}