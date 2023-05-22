#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Member {
protected:
	string id, password, name;
public:
	Member(string input_id, string input_password, string input_name) {
		id = input_id;
		password = input_password;
		name = input_name;
	};
	vector<Member> memberList;
	// 로그인
	bool authenticateMember();
	// 회원 탈퇴
	void deleteMember();
};


class CompanyMember : public Member {
	string  businessNumber;
public:
	CompanyMember(string id, string password, string name, string businessNumber) :Member(id, password, name), businessNumber(businessNumber) {}
};

class NormalMember : public Member {
	string socialSecurityNumber;
public:
	NormalMember(string id, string password, string name, string socialSecurityNumber) :Member(id, password, name), socialSecurityNumber(socialSecurityNumber) {}
};

class Signup {
public:
	void addNewNormalMember(string name, string number, string id, string password, int member_type);
	void addNewCompanyMember(string name, string number, string id, string password, int member_type);
};

class SignupUI {
public:
	void startInterface();
	void createNewMember();
};

class DeleteMember {
public:
	void deleteMember();
};

class DeleteMemberUI {
public:
	void startInterface();
	void withdrawal();
};

class Login {
public:
	void login(string id, string password);
};

class LoginUI {
public:
	void startInterface();
	void insertInfo();
};