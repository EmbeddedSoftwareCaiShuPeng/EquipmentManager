#include "Order.h"

Order::Order() {
	id_ = "";
	date_ = "";
	studentId_ = "";
	studentPhone_ = "";
	userId_ = "";
	equipmentId_ = "";
}

Order::Order(string id, string equipmentId, string userId, string studentId, string studentPhone, string date) {
	id_ = id;
	date_ = date;
	studentId_ = studentId;
	studentPhone_ = studentPhone;
	userId_ = userId;
	equipmentId_ = equipmentId;
}

string Order::getId() {
	return id_;
}

void Order::setId(string id) {
	id_ = id;
}
string Order::getDate() {
	return date_;
}

void Order::setDate(string date) {
	date_ = date;
}

string Order::getStudentId() {
	return studentId_;
}

void Order::setStudentId(string id) {
	studentId_ = id;
}

string Order::getStudentPhone() {
	return studentPhone_;
}

void Order::setStudentPhone(string phone) {
	studentPhone_ = phone;
}

string Order::getUserId() {
	return userId_;
}

void Order::setUserId(string id) {
	userId_ = id;
}

string Order::getEquipmentId() {
	return equipmentId_;
}

void Order::setEquipmentId(string id) {
	equipmentId_ = id;
}