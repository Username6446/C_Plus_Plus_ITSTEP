#pragma once
#include <string>
using std::string;

class UserAccount
{
	string login, password;
public:
	string getLogin() const {
		return login;
	}
	string getPassword() const {
		return password;
	}
	UserAccount(const string& login, const string& password)
		:login{ login }, password{ password }
	{

	}
};

