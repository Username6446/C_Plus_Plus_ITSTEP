#include "SocialNetwork.h"
#include "Exception.h"
void SocialNetwork::checkFormatPassword(const string& pass)
{
	if (pass.length() <= 7) {
		throw WrongPasswordLengthException("Error! Password must be longer than 7 characters.");
	}
	bool hasUpper = false, hasLower = false, hasDigit = false, hasPunc = false;
	for (auto& i : pass)
	{
		if (isupper(i)) hasUpper = true;
		else if (islower(i)) hasLower= true;
		else if (isdigit(i)) hasDigit= true;
		else if (ispunct(i)) hasPunc= true;
	}
	if (!hasUpper || !hasDigit || !hasPunc) {
		throw FormatPasswordException("Error! Password must contain at least one uppercase letter, one digit, and one symbol.");
	}
}

void SocialNetwork::Register(const string& login, const string& password)
{
	for (const auto& u : accounts)
	{
		if (u.getLogin() == login) {
			throw ExistLoginException("Error! This login is already taken.");
		}
	}

	checkFormatPassword(password);

	accounts.push_back(UserAccount(login, password));
	cout << ">>> User " << login << " successfully registered!" << endl;
}

void SocialNetwork::Login() const
{
	string inputLogin, inputPassword;

	cout << "--- Login ---" << endl;
	cout << "Enter login: ";
	cin >> inputLogin;
	cout << "Enter password: ";
	cin >> inputPassword;

	bool userFound = false;

	for (const auto& u : accounts)
	{
		if (u.getLogin() == inputLogin)
		{
			userFound = true;
			if (u.getPassword() == inputPassword) {
				cout << ">>> Welcome back, " << inputLogin << "!" << endl;
				return;
			}
			else {
				throw InvalidPasswordException("Error! Incorrect password.");
			}
		}
	}

	if (!userFound) {
		throw InvalidLoginException("Error! User not found.");
	}
}
