#include "User.h"

User::User(string userName, string userPassword, string studentId, string studentPhone) {	
	userName_ = userName;
	password_ = userPassword;
	studentPhone_ = studentPhone;
	studentId_ = studentId;
}

User::User() {	
	userName_ = "";
	password_ = "";
	studentPhone_ = "";
	studentId_ = "";
}

string User::getName() {	
	return userName_;
}

void User::setName(string name) {
	userName_ = name;
}
	
string User::getPassword() {
	return password_;
}

void User::setPassword(string password){
	password_ = password;
}
	
string User::getStudentPhone() {
	return studentPhone_;
}

void User::setStudentPhone(string phone) {
	studentPhone_ = phone;
}

string User::getStudentId() {
	return studentId_;
}

void User::setStudentId(string id) {
	studentId_ = id;
}
