#pragma once
#include <string>
#include "Login.h"


class LoginUI {
private:
	Login* loginImpl;
public:
	LoginUI(Login* loginImpl) : loginImpl(loginImpl) {};

	void login(const std::string& id, const std::string& password) {
		loginImpl->login(id, password);
	};
};