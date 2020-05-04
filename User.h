#ifndef USER_H
#define USER_H
#include <string.h>
#include <iostream>
#include "Utils.h"
using namespace std;

class User {
protected:
	string username;
	string password;
public:
	User() {
	}
	~User() {
	}
	User(const string user, const string pass) : username(user), password(pass) {}
	User(string line, char delim) {
		vector<string> elems = splitLine(line, delim);
		this->username = elems[1];
		this->password = elems[2];
	}

	User(const User& user)
	{
		this->username = user.username;
		this->password = user.password;
	}
	string getUsername() {
		return this->username;
	}
	string getPassword() {
		return this->password;
	}
	void logout() {
		this->username = "";
		this->password = "";
	}
	User& operator=(const User& user)
	{
		this->username = user.username;
		this->password = user.password;

		return*this;
	}

	bool operator==(const User& user) {
		return this->username.compare(user.username) == 0 && this->password.compare(user.password);
	}
	friend ostream& operator<<(ostream& os, const User& user) {
		os << user.username << "," << user.password;
		return os;
	}
};

#endif // !USER_H
