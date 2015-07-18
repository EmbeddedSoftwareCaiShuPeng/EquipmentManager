#ifndef USER_H
#define  USER_H

#include <string>
using std::string;

class User {
public:
	User(string userName, string userPassword, string studentId, string studentPhone);
	User();
	string getName();
	void setName(string name);
	string getPassword();
	void setPassword(string password);
	string getStudentPhone();
	void setStudentPhone(string phone);
	string getStudentId();
	void setStudentId(string id);

private:
	string userName_;
	string password_;
	string studentId_;
	string studentPhone_;
};

#endif