#include "User.h"

User::User(const std::string& id, const std::string& password, std::string phoneNumber)
    : id(id), password(password), phoneNumber(phoneNumber) {
}

std::string User::getId() const {
    return id;
}

bool User::checkDuplicateId(const std::string& memberId) {
    if (id == memberId) {
        return true;
    }
    return false;
}

bool User::login(const std::string& newId, const std::string& newPassword) {
    if (id == newId && password == newPassword) {
        return true;
    }
    return false;
}