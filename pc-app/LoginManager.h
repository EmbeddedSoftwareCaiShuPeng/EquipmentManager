#ifndef LOGINMANAGER_H
#define LOFINMANAGER_H

#include <string>
#include "UserAccess.h"
#include "AdminAccess.h"

using std::list;

class LoginManager {
public:
	LoginManager();
	~LoginManager();
	bool isUser(string name, string password);
	bool isAdmin(string name, string password);
private:
	UserAccess *userAccess_;
    AdminAccess *adminAccess_;
};

#endif
