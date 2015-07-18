#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include<string>
using std::string;

class Equipment {
public:
	Equipment();
	Equipment(string id, string name, string type, string state);
	string getName();
	void setName(string name);
	string getId();
	void setId(string id);
	string getType();
	void setType(string state);
	string getState();
	void setState(string state);

private:
	string id_;
	string name_;
	string type_;
	string state_;
};

#endif