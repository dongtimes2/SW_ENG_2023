// 헤더 선언
#include <iostream>
#include <vector>
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
    signupUI.showResult();
};

void Signup::addNewMember(int type, string name, int identificationCode, string id, string password, MemberList* pMemberList) {
    pMemberList->addNewMember(type, name, identificationCode, id, password);
    cout << type << " " << name << " " << identificationCode << " " << id << " " << password << endl;
};

Login::Login() {
    LoginUI loginUI;
    loginUI.insertInfo(this);
    loginUI.showResult();
};

Member* Login::login(string id, string password, MemberList* pMemberList) {
    return pMemberList->authenticateMember(id, password);
};

Logout::Logout() {
    LogoutUI logoutUI;
    logoutUI.logout(this);
    logoutUI.showResult();
};

void Logout::logout(Member** pLoggedinMember) {
    *pLoggedinMember = NULL;
};

DeleteMember::DeleteMember() {
    DeleteMemberUI deleteMemberUI;
    deleteMemberUI.withdrawal(this);
    deleteMemberUI.showResult();
};

void DeleteMember::deleteMember(string id, MemberList* pMemberList, Member** pLoggedinMember) {
    pMemberList->deleteMember(id);
   *pLoggedinMember = NULL;
};

AddRecruitment::AddRecruitment() {
    AddRecruitmentUI addRecruitmentUI;
    addRecruitmentUI.createNewRecruitment(this);
    addRecruitmentUI.showResult();
};

void AddRecruitment::addNewRecruitment(string id, string name, int businessNumber, string job, int jobOpenning, string deadline, RecruitmentList* pRecruitmentList) {
    pRecruitmentList->addNewRecruitment(id, name, businessNumber, job, jobOpenning, deadline);
    cout << id << " " << name <<" " << businessNumber << " " << job << " " << jobOpenning << " "<< deadline << endl;
};

CheckRegisteredRecruitment::CheckRegisteredRecruitment(Member* pMember, RecruitmentList* pRecruitmentList) {
    if (pMember) {
        vector<Recruitment*> resultList = pRecruitmentList->getRecuritments(pMember->getId());
        CheckRegisteredRecruitmentUI checkRegisteredRecruitmentUI;

        cout << "테스트: " << resultList.size() << " " << endl;

        for (int i = 0; i < resultList.size(); i++) {
            cout << resultList[i]->getJob() << endl;
        }

        checkRegisteredRecruitmentUI.showResult();

    } else {
        cout << "로그인 하고 있지 않음" << endl;
    }
};
