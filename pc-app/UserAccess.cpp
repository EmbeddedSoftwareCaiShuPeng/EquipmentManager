#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>


#include "UserAccess.h"


UserAccess::UserAccess() {

}

UserAccess::~UserAccess() {

}

bool UserAccess::addUser(User user) {
 	command =  "INSERT INTO User(userName, password, studentId, studentPhone) VALUES('" 
 		+ user.getName() + "', '"
 		+ user.getPassword() + "', '"
 		+ user.getStudentId() +"', '" 
 		+ user.getStudentPhone() + "')" ;

        strToChar();
        if (!query.exec(sqlCommand) ) {
                return false;
       	}

	return true;
}

bool UserAccess::deleteUserByName(string name) {
	command = "DELETE FROM User WHERE userName = '" + name + "';";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return false;
    }

	return true;
}

bool UserAccess::editUser(User user) {
	command = "UPDATE User SET password = '"
		 + user.getPassword() + "',"
         + "studentId = '" +  user.getStudentId() + "',"
		 + "studentPhone = '" +  user.getStudentPhone() + "'"
         + " WHERE userName = '" + user.getName() + "'";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return false;
    }

	return true;
}

User UserAccess::getUserByName(string name) {
    User user;

	command = "SELECT * FROM User WHERE userName = '" + name + "'";
	strToChar();
    if (!query.exec(sqlCommand)) {
            return user;
    }

    while (query.next()) {
                user.setName(query.value(0).toString().toStdString());
                user.setPassword(query.value(1).toString().toStdString());
                user.setStudentId(query.value(2).toString().toStdString());
                user.setStudentPhone(query.value(3).toString().toStdString());
    }

	return user;
}

list<User> UserAccess::getUserByKeyword(string keyword) {
	list<User> userList;

	command = "SELECT * FROM User WHERE (userName LIKE '%" 
		+ keyword + "%') "
		+ "| (studentId LIKE '%" + keyword + "%') "
		+ "| (studentPhone LIKE '%" + keyword + "%') ";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return userList;
    }

    while (query.next()) {
                User user;
                user.setName(query.value(0).toString().toStdString());
                user.setPassword(query.value(1).toString().toStdString());
                user.setStudentId(query.value(2).toString().toStdString());
                user.setStudentPhone(query.value(3).toString().toStdString());
        		userList.push_back(user);
    }

	return userList;
}

list<User> UserAccess::getAllUser() {
	list<User> userList;

	command = "SELECT * FROM User";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return userList;
    }

    while (query.next()) {
                User user;
                user.setName(query.value(0).toString().toStdString());
                user.setPassword(query.value(1).toString().toStdString());
                user.setStudentId(query.value(2).toString().toStdString());
                user.setStudentPhone(query.value(3).toString().toStdString());
                userList.push_back(user);
    }

	return userList;
}

void UserAccess::strToChar() {
    unsigned int i;
	for (i = 0; i < command.length(); i++) {
		sqlCommand[i] = command[i];
	}
	sqlCommand[i] = '\0';
}
