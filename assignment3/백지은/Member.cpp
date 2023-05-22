#include "header.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 변수 선언
FILE* in_fp, * out_fp;

vector<Member> memberList;

bool Member::authenticateMember() {
	// 로그인 기능
	// member 클래스의 id, pw 비교 bool값

	fprintf(out_fp, "> %s %s", id, password);
}

void Member::deleteMember() {

}