#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

#include "AdminAccess.h"


AdminAccess::AdminAccess() {
}

AdminAccess::~AdminAccess() {
}


Admin AdminAccess::getAdminByName(string name) {
    Admin admin;

    command = "SELECT * FROM Admin WHERE adminName = '" + name + "'";

    strToChar();
    if (!query.exec(sqlCommand)) {
            QMessageBox::critical(0,QObject::tr("Database Error"),conn.lastError().text());
            return admin;
    }

    while (query.next()) {
                admin.setName(query.value(0).toString().toStdString());
                admin.setPassword(query.value(1).toString().toStdString());
    }

    return admin;
}

void AdminAccess::strToChar() {
    unsigned int i;
	for (i = 0; i < command.length(); i++) {
		sqlCommand[i] = command[i];
	}
	sqlCommand[i] = '\0';
}
