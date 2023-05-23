// 헤더 선언
#include <iostream>
#include <vector>
#include <map>
#include "header.h"
using namespace std;

Signup::Signup() {
    SignupUI signupUI;
    signupUI.createNewMember(this);
    signupUI.showResult();
};

void Signup::addNewMember(int type, string name, int identificationCode, string id, string password, MemberList* pMemberList) {
    pMemberList->addNewMember(type, name, identificationCode, id, password);
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
};

CheckRegisteredRecruitment::CheckRegisteredRecruitment(Member* pMember, RecruitmentList* pRecruitmentList) {
    vector<Recruitment*> resultList = pRecruitmentList->getRecuritments(pMember->getName());
    CheckRegisteredRecruitmentUI checkRegisteredRecruitmentUI;
    checkRegisteredRecruitmentUI.showResult(resultList);
};

SearchRecruitment::SearchRecruitment() {
    SearchRecruitmentUI searchRecruitmentUI;
    searchRecruitmentUI.insertSearchValue(this);
};

void SearchRecruitment::showRecruitments(string companyName, RecruitmentList* pRecruitmentList) {
    vector<Recruitment*> resultList = pRecruitmentList->getRecuritments(companyName);
    SearchRecruitmentUI searchRecruitmentUI;
    searchRecruitmentUI.showResult(resultList);
};

ApplyCompany::ApplyCompany() {
    ApplyCompanyUI applyCompanyUI;
    ApplicationData resultData = applyCompanyUI.selectRecruitment(this);
    applyCompanyUI.showResult(resultData.companyName, resultData.targetBusinessNumber, resultData.job);
};

ApplicationData ApplyCompany::addNewApplication(int businessNumber, string normalMemberId, RecruitmentList* pRecruitmentList, ApplicationList* pApplicationList) {
    vector<Recruitment*> resultList = pRecruitmentList->getRecuritments(businessNumber);
    ApplyCompanyUI applyCompanyUI;
    ApplicationData resultData;
    pApplicationList->addNewApplication(
        normalMemberId,
        resultList[0]->getCompanyName(),
        resultList[0]->getBusinessNumber(),
        resultList[0]->getJob(),
        resultList[0]->getJobOpenning(),
        resultList[0]->getDeadline()
    );
    resultData.companyName = resultList[0]->getCompanyName();
    resultData.targetBusinessNumber = resultList[0]->getBusinessNumber();
    resultData.job = resultList[0]->getJob();

    return resultData;
};

CheckApplication::CheckApplication(Member* pMember, ApplicationList* pApplicationList) {
    vector<Application*> resultList = pApplicationList->getApplications(pMember->getId());
    CheckApplicationUI checkApplicationUI;
    checkApplicationUI.showResult(resultList);
};

CancelApplication::CancelApplication() {
    CancelApplicationUI cancelApplicationUI;
    ApplicationData resultData = cancelApplicationUI.cancelApplication(this);
    cancelApplicationUI.showResult(resultData.companyName, resultData.targetBusinessNumber, resultData.job);
};

ApplicationData CancelApplication::cancelApplication(string normalMemberId, int businessNumber, ApplicationList* pApplicationList) {
    ApplicationData resultData = pApplicationList->cancelApplication(normalMemberId, businessNumber);

    return resultData;
};

CheckStatistic::CheckStatistic(Member* pMember, ApplicationList* pApplicationList) {
    CheckStatisticUI checkStatisticUI;

    if (pMember->getType() == COMPANY_MEMBER) {
        vector<Application*> resultList = pApplicationList->getApplications(pMember->getIdentificationCode());
        map<string, int> applicantCountsByJob;

        for (int i = 0; i < resultList.size(); i++) {
            string job = resultList[i]->getJob();

            if (applicantCountsByJob.count(job) > 0) {
                applicantCountsByJob[job]++;
            } else {
                applicantCountsByJob[job] = 1;
            }
        }

        checkStatisticUI.showResult(applicantCountsByJob);

    } else if (pMember->getType() == NORMAL_MEMBER) {
        vector<Application*> resultList = pApplicationList->getApplications(pMember->getId());
        map<string, int> applicationCountsByJob;

        for (int i = 0; i < resultList.size(); i++) {
            string job = resultList[i]->getJob();

            if (applicationCountsByJob.count(job) > 0) {
                applicationCountsByJob[job]++;
            } else {
                applicationCountsByJob[job] = 1;
            }
        }

        checkStatisticUI.showResult(applicationCountsByJob);
    }
};
