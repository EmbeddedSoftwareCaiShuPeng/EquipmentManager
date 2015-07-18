#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <list>
#include "User.h"
#include "UserAccess.h"

using std::string;
using std::list;

class UserManager {
public:
	UserManager();
	~UserManager();
	bool isExist(string userName);
	bool addUser(User user);
	bool deleteUser(User user);
	bool editUser(User user);
    list<User> searchUser(string keyword);
	list<User> getAllUser(); 
private:
	UserAccess *userAccess_;
};

#endif
