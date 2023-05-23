// 헤더 선언
#include <iostream>
#include "header.h"

void Member::setType(int type) {
	this->type = type;
};

void Member::setId(string id) {
	this->id = id;
};

void Member::setName(string name) {
	this->name = name;
};

void Member::setPassword(string password) {
	this->password = password;
};

int Member::getType() {
	return this->type;
};

string Member::getId() {
	return this->id;
};

string Member::getName() {
	return this->name;
};

string Member::getPassword() {
	return this->password;
};

