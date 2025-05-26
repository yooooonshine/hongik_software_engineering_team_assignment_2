#pragma once
#include <string>

class User {
protected:
	std::string id;
	std::string password;
	std::string phoneNumber;

public:
	User(const std::string& id, const std::string& password, std::string phoneNumber);

	virtual ~User() = default;

	std::string getId() const;

	bool checkDuplicateId(const std::string& id);

	bool login(const std::string& id, const std::string& password);
};