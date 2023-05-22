#include "header.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 변수 선언
FILE* in_fp, * out_fp;

void LoginUI::startInterface() {
	fprintf(out_fp, "2.1. 로그인\n");
}

void LoginUI::insertInfo() {
	string id, password;
	fscanf(in_fp, "%s %s", id, password);

	Login* NewLogin = new Login;
	NewLogin->login(id, password);
	// Login클래스의 login()이	Member클래스의 auth() 불러서 로그인
}

