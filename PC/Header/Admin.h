#ifndef ADMIN_H
#define ADMIN_H

#include<string>
using std::string;

class Admin {
public:
	Admin();
	Admin(string adminName,  string adminPassword);
	string getName();
	void setName(string name);
	string getPassword();
	void setPassword(string password);
private:
	string name_;
	string password_;
};

#endif