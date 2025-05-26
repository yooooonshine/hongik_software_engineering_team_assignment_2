#pragma once
#include <string>

struct BicycleDetails {
    std::string id;
    std::string name;
    std::string renterId;

    BicycleDetails(const std::string& id, const std::string& name, const std::string& renterId)
        : id(id), name(name), renterId(renterId) {
    }
};