#include "Equipment.h"

Equipment::Equipment() {
	name_ = "";
	id_ = "";
	type_ = "";
	state_ = "";
}

Equipment::Equipment(string id, string name, string type, string state) {
	name_ = name;
	id_ = id;
	type_ = type;
	state_ = state;
}

string Equipment::getName() {
	return name_;
}

void Equipment::setName(string name) {
	name_ = name;
}

string Equipment::getId() {
	return id_;
}

void Equipment::setId(string id) {
	id_ = id;
}
	
string Equipment::getType() {
	return type_;
}

void Equipment::setType(string type) {
	type_ = type;
}
	
string Equipment::getState() {
	return state_;
}
	
void Equipment::setState(string state) {
	state_ = state;
}
