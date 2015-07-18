#include "OrderManager.h"

OrderManager::OrderManager(string userId) {
	orderAccess_ = new OrderAccess();
	equipmentAccess_ = new EquipmentAccess();
	userId_ = userId;
}

OrderManager::~OrderManager() {
	delete orderAccess_;
	delete equipmentAccess_;
}

bool OrderManager::lendEquipment(Order order) {
	Equipment equipment;

	equipment = equipmentAccess_->getEquipmentById(order.getEquipmentId());
    if (equipment.getId() == "" || equipment.getState() != "IN") {
		return false;
	}

	order.setUserId(userId_);
    equipment.setState("OUT");
    if (equipmentAccess_->editEquipment(equipment))
        return orderAccess_->addOrder(order);
    else
        return false;
}

bool OrderManager::returnEquipment(Order order) {
    Equipment equipment;

    equipment = equipmentAccess_->getEquipmentById(order.getEquipmentId());
    if (orderAccess_->deleteOrderById(order.getId())) {
        equipment.setState("IN");
        equipmentAccess_->editEquipment(equipment);
        return true;
    }else {
        return false;
    }
}

list<Order> OrderManager::searchOrder(string keyword) {
	return orderAccess_->getOrderByKeyword(keyword);
}

list<Order> OrderManager::getAllOrder() {
	return orderAccess_->getAllOrder();
}
