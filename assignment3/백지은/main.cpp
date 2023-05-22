// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
#include "header.h"

using namespace std;

// 상수 선언
#define INPUT_FILE_NAME "input.txt“
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void join();
void withdrawal();
void login();

// 변수 선언
FILE* in_fp, * out_fp;

// doTask()에 들어갈 함수들
// 회원가입
void join() {
	SignupUI* NewSignupUI = new SignupUI;
	NewSignupUI->startInterface();
	NewSignupUI->createNewMember();
}

// 회원탈퇴
void withdrawal() {
	DeleteMemberUI* NewDeleteMemberUI = new DeleteMemberUI;
	NewDeleteMemberUI->startInterface();
	NewDeleteMemberUI->withdrawal();
}

// 로그인
void login() {
	LoginUI* NewLoginUI = new LoginUI;
	NewLoginUI->startInterface();
	NewLoginUI->insertInfo();
}

