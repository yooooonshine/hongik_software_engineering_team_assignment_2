#pragma once

#include <string>
#include "UserManager.h"

class AddMember {
private:
    UserManager* userManager;

public:
    AddMember(UserManager* userManager);

    void addNewMember(const std::string& id, const std::string& password, const std::string& phoneNumber);
};