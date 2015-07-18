#include "EquipmentManager.h"

EquipmentManager::EquipmentManager() {
	equipmentAccess_ = new EquipmentAccess();
}

EquipmentManager::~EquipmentManager() {
	delete equipmentAccess_;
}

bool EquipmentManager::isExist(string id) {
	Equipment equipment;

	equipment = equipmentAccess_->getEquipmentById(id);
	if (equipment.getId() == "")
		return false;
	else
		return true;
}

bool EquipmentManager::addEquipment(Equipment equipment) {
	return equipmentAccess_->addEquipment(equipment);
}

bool EquipmentManager::deleteEquipment(Equipment equipment) {
    if (equipment.getId() == "" || equipment.getState() == "OUT")
		return false;
	else 
		return equipmentAccess_->deleteEquipmentById(equipment.getId());
}

bool EquipmentManager::editEquipment(Equipment equipment) {
	if (!isExist(equipment.getId())) 
		return false;
	else
		return equipmentAccess_->editEquipment(equipment);
}

list<Equipment> EquipmentManager::searchEquipment(string keyword) {
	return equipmentAccess_->getEquipmentByKeyword(keyword);
}

list<Equipment> EquipmentManager::getAllEquipment() {
	return equipmentAccess_->getAllEquipment();
}
