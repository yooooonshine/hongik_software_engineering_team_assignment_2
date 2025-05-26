#pragma once
#include <string>
#include "AddMember.h"


class AddMemberUI {
private:
	AddMember* addMember;
public:
	AddMemberUI(AddMember* addMember) : addMember(addMember) {};

	void addNewMember(const std::string& id, const std::string& password, const std::string phoneNumber) {
		addMember->addNewMember(id, password, phoneNumber);
	};
};