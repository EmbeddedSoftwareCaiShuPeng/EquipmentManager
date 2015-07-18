#include "LoginManager.h"

LoginManager::LoginManager() {
	userAccess_ = new UserAccess();
    adminAccess_ = new AdminAccess();
}

LoginManager::~LoginManager() {
	delete userAccess_;
    delete adminAccess_;
}

bool LoginManager::isUser(string name, string password) {
	User user;

	user = userAccess_->getUserByName(name);
	if (user.getName() != "" && user.getPassword() == password)
		return true;
	return false;
}

bool LoginManager::isAdmin(string name, string password) {
    Admin admin;

    admin = adminAccess_->getAdminByName(name);
	if (admin.getName() != "" && admin.getPassword() == password)
        return true;
	return false;
}
