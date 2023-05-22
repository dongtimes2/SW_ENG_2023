#include "header.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 변수 선언
FILE* in_fp, * out_fp;

void SignupUI::startInterface() {
	fprintf(out_fp, "1.1. 회원가입\n");
}

void SignupUI::createNewMember() {
	int member_type;
	string name, number, id, password;

	fscanf(in_fp, "%d %s %s %s %s", member_type, name, number, id, password);

	Signup* NewSignup = new Signup;
	if (member_type == 1) {
		NewSignup->addNewCompanyMember(name, number, id, password, member_type);
	}
	else if (member_type == 2) {
		NewSignup->addNewNormalMember(name, number, id, password, member_type);
	}
}
