#ifndef USERACCESS_H
#define USERACCESS_H

#include <string>
#include <list>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "User.h"

using std::string;
using std::list;

extern QSqlDatabase conn;
extern QSqlQuery query;

class UserAccess {
public:
	UserAccess();
	~UserAccess();
	bool addUser(User user);
	bool deleteUserByName(string id);
	bool editUser(User user);
	User getUserByName(string name);
	list<User> getUserByKeyword(string keyword);
	list<User> getAllUser();
	void strToChar();

private:
	string command;
	char sqlCommand[200];
};

#endif
