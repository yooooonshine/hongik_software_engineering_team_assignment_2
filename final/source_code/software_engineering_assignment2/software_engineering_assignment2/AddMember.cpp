#pragma once
#include <string>
#include "Member.h"
#include "Login.h"

class AddMember {
private:
	UserManager* userManager;

public:
	AddMember(UserManager* userManager) : userManager(userManager) {};

	void addNewMember(const std::string& id, const std::string& password, std::string phoneNumber) {
		Member member(id, password, phoneNumber);

		userManager->addUser(member);
	}
};