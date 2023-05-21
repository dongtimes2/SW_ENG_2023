#include "header.h"

void Member::setId(string id) {
  this->id = id;
};

void Member::setName(string name) {
  this->name = name;
};

void Member::setPassword(string password) {
  this->password = password;
};

string Member::getName() {
    return this->name;
};