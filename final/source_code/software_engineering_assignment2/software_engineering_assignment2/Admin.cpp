#pragma once
#include "User.h"

class Admin : public User {
public:
	Admin(const std::string& id, const std::string& password, const std::string& phoneNumber)
		: User(id, password, phoneNumber) {}
};


