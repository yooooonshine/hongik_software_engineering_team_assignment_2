#pragma once
#include "User.h"
#include <vector>


class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& user) {
        users.push_back(user);
    }

    std::vector<User> getAllUsers() const {
        return users;
    }

    User* findUserById(const std::string& id) {
        for (auto& user : users) {
            if (user.getId() == id) {
                return &user;
            }
        }
        return nullptr;
    }
};
