#ifndef EQUIPMENTMANAGER_H
#define EQUIPMENTMANAGER_H

#include <string>
#include "Equipment.h"
#include "EquipmentAccess.h"

using std::string;
using std::list;

class EquipmentManager {
public:
	EquipmentManager();
	~EquipmentManager();
	bool isExist(string id);
	bool addEquipment(Equipment equipment);
	bool deleteEquipment(Equipment equipment);
	bool editEquipment(Equipment equipment);
    list<Equipment> searchEquipment(string keyword);
	list<Equipment> getAllEquipment(); 
private:
	EquipmentAccess *equipmentAccess_;
};

#endif
