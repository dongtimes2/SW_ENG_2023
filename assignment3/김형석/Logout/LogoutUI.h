#pragma once
#include <iostream>
#include "Logout.h"
#include "header.h"
using namespace std;

class Logout;
class Member;

class LogoutUI {
private :
	Logout* control;
public :
	LogoutUI();
	void startInterface(Logout* );
	void logout(Member* );
};