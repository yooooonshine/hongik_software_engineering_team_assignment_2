#pragma once
#include "User.h"
#include "Bicycle.h"
#include <vector>
#include <string>

class Member : public User {
private:
    std::vector<Bicycle> bicycles;

public:
    Member(const std::string& id, const std::string& password, std::string phoneNumber);

    std::vector<Bicycle> listBicycles() const;
    void rent(Bicycle& bike);
};
