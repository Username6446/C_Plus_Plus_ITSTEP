#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;
class Exception : public exception
{
	string message;
public:
	Exception(const string& message = "None message")
		:exception(message.data())
	{ }
};

class FormatPasswordException : public Exception
{
public:
	FormatPasswordException(const string& message = "Invalid format password")
		:Exception(message)
	{

	}
};

class ExistLoginException : public Exception
{
public:
	ExistLoginException(const string& message = "Exception Login exist ")
		:Exception(message)
	{

	}
};

class WrongPasswordLengthException : public Exception {
public:
	WrongPasswordLengthException(const string& message = "Exception Wrong Password Length ")
		:Exception(message)
	{

	}
};

class InvalidLoginException : public Exception {
public:
	InvalidLoginException(const string& message = "Invalid Login ")
		:Exception(message)
	{

	}
};

class InvalidPasswordException : public Exception {
public:
	InvalidPasswordException(const string& message = "Invalid Password")
		:Exception(message)
	{

	}
};