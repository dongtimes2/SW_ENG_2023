#include "header.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 변수 선언
FILE* in_fp, * out_fp;

void Signup::addNewCompanyMember(string name, string number, string id, string password, int member_type) {
	CompanyMember* NewCompanyMember = new CompanyMember(id, password, name, number);
	// memberList.push_back(NewCompanyMember); 벡터 정의한 헤더파일 따로?
	fprintf(out_fp, "> %d %s %s %s %s\n", member_type, name, number, id, password);
}

void Signup::addNewNormalMember(string name, string number, string id, string password, int member_type) {
	NormalMember* NewNormalMember = new NormalMember(id, password, name, number);
	fprintf(out_fp, "> %d %s %s %s %s\n", member_type, name, number, id, password);
}
