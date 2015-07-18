#ifndef ADMINACCESS_H
#define ADMINACCESS_H

#include <string>
#include <list>
#include <mysql/mysql.h>
#include "Admin.h"

using std::string;
using std::list;

extern QSqlDatabase conn;
extern QSqlQuery query;

class AdminAccess {
public:
	AdminAccess();
	~AdminAccess();
	Admin getAdminByName(string name);
	void strToChar();

private:
	string command;
	char sqlCommand[300];
};

#endif
