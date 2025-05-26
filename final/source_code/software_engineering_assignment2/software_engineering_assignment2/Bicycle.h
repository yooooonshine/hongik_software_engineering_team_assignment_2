#pragma once
#include <string>
#include "BicycleDetails.h"

class Bicycle {
private:
	std::string id;
	std::string name;
	std::string renterId;

public:
	Bicycle(const std::string& id, const std::string& name);

	BicycleDetails getBicycleDetails() const;

	bool isRented() const;

	void rentTo(const std::string& userId);

	void returnBicycle();

	std::string getBicycleId() const;
};