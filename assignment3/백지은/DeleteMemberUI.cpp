#include "header.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// 변수 선언
FILE* in_fp, * out_fp;

void DeleteMemberUI::startInterface() {
	fprintf(out_fp, "1.2. 회원탈퇴\n");
}

void DeleteMemberUI::withdrawal() {
	DeleteMember* NewDeleteMember = new DeleteMember;
	NewDeleteMember->deleteMember();
	// 탈퇴 요청, deletemember의 deleteMember() 부르기
}