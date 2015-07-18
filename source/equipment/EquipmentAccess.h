#ifndef EQUIPMENTACCESS_H
#define EQUIPMENTACCESS_H

#include <string>
#include <list>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "Equipment.h"

using std::string;
using std::list;

extern QSqlDatabase conn;
extern QSqlQuery query;

class EquipmentAccess {
public:
	EquipmentAccess();
	~EquipmentAccess();
	bool addEquipment(Equipment equipment);
	bool deleteEquipmentById(string id);
	bool editEquipment(Equipment equipment);
	Equipment getEquipmentById(string id);
	list<Equipment> getEquipmentByKeyword(string keyword);
	list<Equipment> getAllEquipment();
	void strToChar();

private:
	string command;
	char sqlCommand[200];
};

#endif
