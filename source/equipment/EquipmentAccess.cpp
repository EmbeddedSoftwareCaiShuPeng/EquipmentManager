#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QSqlError>
#include <QVariant>

#include "EquipmentAccess.h"

EquipmentAccess::EquipmentAccess() {
}

EquipmentAccess::~EquipmentAccess() {
}

bool EquipmentAccess::addEquipment(Equipment equipment) {
 	command =  "INSERT INTO Equipment(id, name, type, state) VALUES('" 
 		+ equipment.getId() +"', '" 
 		+ equipment.getName() + "', '"
 		+ equipment.getType() + "', '"
 		+ equipment.getState() + "')" ;

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return false;
    }

	return true;
}

bool EquipmentAccess::deleteEquipmentById(string id) {
	command = "DELETE FROM Equipment WHERE id = '" + id + "'";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return false;
    }

	return true;
}

bool EquipmentAccess::editEquipment(Equipment equipment) {
	command = "UPDATE Equipment SET id = '"
		+ equipment.getId() + "', "
		+ "name = '" + equipment.getName() + "', "
		+ "type = '" + equipment.getType() + "',"
		+ "state = '" +  equipment.getState() + "'"
		+ "WHERE id = '" + equipment.getId() + "'";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return false;
    }

	return true;
}

Equipment EquipmentAccess::getEquipmentById(string id) {
    Equipment equipment;
	command = "SELECT * FROM Equipment WHERE id = '" + id + "'";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return equipment;
    }

    while (query.next()) {
                equipment.setId(query.value(0).toString().toStdString());
                equipment.setName(query.value(1).toString().toStdString());
                equipment.setType(query.value(2).toString().toStdString());
                equipment.setState(query.value(3).toString().toStdString());
    }

	return equipment;
}

list<Equipment> EquipmentAccess::getEquipmentByKeyword(string keyword) {
	list<Equipment> equipmentList;
    Equipment equipment;

	command = "SELECT * FROM Equipment WHERE (id LIKE '%" 
		+ keyword + "%') "
		+ "| (name LIKE '%" + keyword + "%') "
		+ "| (type LIKE '%" + keyword + "%') "
		+ "| (state LIKE '%" + keyword + "%') ";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return equipmentList;
    }

    while (query.next()) {
                equipment.setId(query.value(0).toString().toStdString());
                equipment.setName(query.value(1).toString().toStdString());
                equipment.setType(query.value(2).toString().toStdString());
                equipment.setState(query.value(3).toString().toStdString());
                equipmentList.push_back(equipment);
    }

	return equipmentList;
}

list<Equipment> EquipmentAccess::getAllEquipment() {
	list<Equipment> equipmentList;
    Equipment equipment;

	command = "SELECT * FROM Equipment";

	strToChar();
    if (!query.exec(sqlCommand) ) {
            return equipmentList;
    }

    while (query.next()) {
                equipment.setId(query.value(0).toString().toStdString());
                equipment.setName(query.value(1).toString().toStdString());
                equipment.setType(query.value(2).toString().toStdString());
                equipment.setState(query.value(3).toString().toStdString());
                equipmentList.push_back(equipment);
    }

	return equipmentList;
}

void EquipmentAccess::strToChar() {
    unsigned int i;
	for (i = 0; i < command.length(); i++) {
		sqlCommand[i] = command[i];
	}
	sqlCommand[i] = '\0';
}
