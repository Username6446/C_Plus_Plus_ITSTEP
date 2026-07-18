#pragma once
#include <vector>
#include "UserAccount.h"
using std::vector;
class SocialNetwork
{
	vector<UserAccount> accounts;
	void checkFormatPassword(const string& pass);
public:
	void Register(const string& login, const string& password);
	void Login() const;
};

