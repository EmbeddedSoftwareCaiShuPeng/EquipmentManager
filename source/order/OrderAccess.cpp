#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

#include "OrderAccess.h"

OrderAccess::OrderAccess() {

}

OrderAccess::~OrderAccess() {

}

bool OrderAccess::addOrder(Order order) {
 	command =  "INSERT INTO Order_(equipmentId, userId, studentId, studentPhone) VALUES('" 
 		+ order.getEquipmentId() +"', '" 
 		+ order.getUserId() + "', '"
 		+ order.getStudentId() + "', '"
 		+ order.getStudentPhone() + "')" ;

	strToChar();
    if (!query.exec(sqlCommand) ) {
        return false;
     }
	return true;
}

bool OrderAccess::deleteOrderById(string id) {
	command = "DELETE FROM Order_ WHERE id = " + id;

	strToChar();
    if (!query.exec(sqlCommand) ) {
        QMessageBox::critical(0,QObject::tr("Database Error"),conn.lastError().text());
        return false;
     }

	return true;
}

Order OrderAccess::getOrderById(string id) {
    Order order;
	command = "SELECT * FROM Order_ WHERE id = " + id;

	strToChar();
    if (!query.exec(sqlCommand)) {
        return order;
    }

    while (query.next()) {
        order.setId(query.value(0).toString().toStdString());
        order.setEquipmentId(query.value(1).toString().toStdString());
        order.setUserId(query.value(2).toString().toStdString());
        order.setStudentId(query.value(3).toString().toStdString());
        order.setStudentPhone(query.value(2).toString().toStdString());
        order.setDate(query.value(3).toString().toStdString());
    }

	return order;
}

list<Order> OrderAccess::getOrderByKeyword(string keyword) {
	list<Order> orderList;
    Order order;

	command = "SELECT * FROM Order_ WHERE (id LIKE '%" 
		+ keyword + "%') "
		+ "| (equipmentId LIKE '%" + keyword + "%') "
		+ "| (userId LIKE '%" + keyword + "%') "
		+ "| (studentId LIKE '%" + keyword + "%') "
		+ "| (studentPhone LIKE '%" + keyword + "%') "
		+ "| (date LIKE '%" + keyword + "%') ";

	strToChar();
    if (!query.exec(sqlCommand)) {
        return orderList;
    }

    while (query.next()) {
        order.setId(query.value(0).toString().toStdString());
        order.setEquipmentId(query.value(1).toString().toStdString());
        order.setUserId(query.value(2).toString().toStdString());
        order.setStudentId(query.value(3).toString().toStdString());
        order.setStudentPhone(query.value(4).toString().toStdString());
        order.setDate(query.value(5).toString().toStdString());
        orderList.push_back(order);
    }

	return orderList;
}

list<Order> OrderAccess::getAllOrder() {
	list<Order> orderList;
    Order order;

	command = "SELECT * FROM Order_";

	strToChar();
    if (!query.exec(sqlCommand)) {
        return orderList;
    }

    while (query.next()) {
        order.setId(query.value(0).toString().toStdString());
        order.setEquipmentId(query.value(1).toString().toStdString());
        order.setUserId(query.value(2).toString().toStdString());
        order.setStudentId(query.value(3).toString().toStdString());
        order.setStudentPhone(query.value(4).toString().toStdString());
        order.setDate(query.value(5).toString().toStdString());
        orderList.push_back(order);
    }

	return orderList;
}

void OrderAccess::strToChar() {
    unsigned int i;
	for (i = 0; i < command.length(); i++) {
		sqlCommand[i] = command[i];
	}
	sqlCommand[i] = '\0';
}
