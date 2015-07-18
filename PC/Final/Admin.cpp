#include "Admin.h"

Admin::Admin(string adminName, string adminPassword) {	
	name_ = adminName;
	password_ = adminPassword;
}

Admin::Admin() {	
	name_ = "";
	password_ = "";
}

string Admin::getName() {	
	return name_;
}

void Admin::setName(string name) {
	name_ = name;
}
	
string Admin::getPassword() {
	return password_;
}

void Admin::setPassword(string password){
	password_ = password;
}
	