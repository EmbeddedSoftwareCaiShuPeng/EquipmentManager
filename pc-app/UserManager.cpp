#include "UserManager.h"
#include <stdio.h>
UserManager::UserManager() {
	userAccess_ = new UserAccess();
}

UserManager::~UserManager() {
	delete userAccess_;
}

bool UserManager::isExist(string userName) {
	User user;
	
	user = userAccess_->getUserByName(userName);
	if (user.getName() == "")
		return false;
	else
		return true;
}

bool UserManager::addUser(User user) {
	return	userAccess_->addUser(user);
}

bool UserManager::deleteUser(User user) {
	if (user.getName() == "")
		return false;
	else 
		return userAccess_->deleteUserByName(user.getName());
}

bool UserManager::editUser(User user) {
    if (!isExist(user.getName()))
        return false;
    else
		return userAccess_->editUser(user);
}

list<User> UserManager::searchUser(string keyword) {
	return userAccess_->getUserByKeyword(keyword);
}

list<User> UserManager::getAllUser() {
	return userAccess_->getAllUser();
}
