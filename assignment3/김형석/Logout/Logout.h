#pragma once
#include <string>
#include "header.h"

class LogoutUI;
class Member;

class Logout {
private :
	LogoutUI* ui;
public :
	Logout();
	void logout(Member* newMember);
};