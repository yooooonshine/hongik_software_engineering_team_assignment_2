#pragma once

#include <string>

class AddMember;

class AddMemberUI {
private:
    AddMember* addMember;

public:
    AddMemberUI(AddMember* addMember);

    void addNewMember(const std::string& id, const std::string& password, const std::string phoneNumber);
};
