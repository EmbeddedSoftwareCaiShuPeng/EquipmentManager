#ifndef ORDER_H
#define ORDER_H

#include<string>

#include"Equipment.h"
#include"User.h"

using std::string;

class Order {
public:
	Order();
	Order(string id, string equipmentId, string userId, string studentId, string studentPhone, string date);
	string getId();
	void setId(string id);
	string getDate();
	void setDate(string Date);
	string getStudentId();
	void setStudentId(string id);
	string getStudentPhone();
	void setStudentPhone(string phone);
	string getUserId();
	void setUserId(string id);
	string getEquipmentId();
	void setEquipmentId(string id);

private:
	string id_;
	string equipmentId_;
	string userId_;
	string studentId_;
	string studentPhone_;
	string date_;
};

#endif