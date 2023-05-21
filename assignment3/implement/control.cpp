// 헤더 선언
#include <iostream>
#include "header.h"
using namespace std;

ApplyCompany::ApplyCompany() {
    //
};

CancelApplication::CancelApplication() {
    //
};

CheckApplication::CheckApplication() {
    cout << "hello" << endl;
};

Signup::Signup() {
    SignupUI signupUI;
    signupUI.createNewMember(this);
};

void Signup::addNewMember(int type, string name, int identificationCode, string id, string password, MemberList* memberList) {
    memberList->addNewMember(type, name, identificationCode, id, password);
    cout << type << name << identificationCode << id << password << endl;
};