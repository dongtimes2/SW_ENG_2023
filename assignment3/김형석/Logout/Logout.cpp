#include <iostream>
#include "Logout.h"
#include "LogoutUI.h"

using namespace std;

Logout::Logout() {
	this->logoutUI = new LogoutUI;
	this->logoutUI->startInterface(this);

}


void Logout::logout(Member* newMember) {

	newMember = NULL;

}

