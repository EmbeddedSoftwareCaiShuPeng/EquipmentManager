#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <string>
#include <list>
#include "OrderAccess.h"
#include "User.h"
#include "Equipment.h"
#include "UserAccess.h"
#include "EquipmentAccess.h"

using std::list;
using std::string;

class OrderManager {
public:
	OrderManager(string userId);
	~OrderManager();
	bool lendEquipment(Order order);
	bool returnEquipment(Order order);
    list<Order> searchOrder(string keyword);
	list<Order> getAllOrder();

private:
	OrderAccess *orderAccess_;
	EquipmentAccess *equipmentAccess_;
	string userId_;
};

#endif
