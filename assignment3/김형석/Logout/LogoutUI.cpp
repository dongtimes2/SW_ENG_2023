#include <iostream>
#include "LogoutUI.h"
#include "Logout.h"

using namespace std;

void LogoutUI::startInterface(Logout* logout) {

	this->control = logout;
}

void LogoutUI::startInterface(Member* newMember) {
	cout << "2.2 �α׾ƿ�" << endl;
	cout << ">" << newMember->getName() << endl;
	this->control->logout(newMember);
}