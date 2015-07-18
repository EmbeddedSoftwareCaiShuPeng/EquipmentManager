#ifndef ORDERACCESS_H
#define ORDERACCESS_H

#include <string>
#include <list>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "Order.h"

using std::string;
using std::list;

extern QSqlDatabase conn;
extern QSqlQuery query;

class OrderAccess {
public:
	OrderAccess();
	~OrderAccess();
	bool addOrder(Order order);
	bool deleteOrderById(string id);
	Order getOrderById(string id);
	list<Order> getOrderByKeyword(string keyword);
	list<Order> getAllOrder();
	void strToChar();

private:
	string command;
	char sqlCommand[300];
};

#endif
