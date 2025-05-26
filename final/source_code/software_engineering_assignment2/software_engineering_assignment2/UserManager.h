#pragma once

#include <vector>
#include <string>
#include "User.h"

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& user);
    std::vector<User> getAllUsers() const;
    User* findUserById(const std::string& id);
};