// 헤더 선언
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// 상수 선언
#define MAX_NUMBER 100
#define COMPANY_MEMBER 1
#define NORMAL_MEMBER 2

struct ApplicationData {
    string companyName;
    string job;
    int targetBusinessNumber;
};

class Recruitment {
    private:
        string companyId;
        string companyName;
        int businessNumber;
        string job;
        int jobOpenning;
        string deadline;

    public:
        void setCompanyId(string);
        void setCompanyName(string);
        void setBusinessNumber(int);
        void setJob(string);
        void setJobOpenning(int);
        void setDeadline(string);
        string getCompanyId();
        string getCompanyName();
        int getBusinessNumber();
        string getJob();
        int getJobOpenning();
        string getDeadline();
};

class RecruitmentList {
    private:
        Recruitment* recruitmentList[MAX_NUMBER];
        int index;

    public:
        RecruitmentList():index(0) {};
        void addNewRecruitment(string, string, int, string, int, string);
        vector<Recruitment*> getRecuritments(string);
        vector<Recruitment*> getRecuritments(int);
};

class Application {
    private:
        string normalMemberId;
        string companyName;
        int businessNumber;
        string job;
        int jobOpenning;
        string deadline;

    public:
        void setNormalMemberId(string);
        void setCompnayName(string);
        void setBusinessNumber(int);
        void setJob(string);
        void setJobOpenning(int);
        void setDeadline(string);
        string getNormalMemberId();
        string getCompanyName();
        int getBusinessNumber();
        string getJob();
        int getJobOpenning();
        string getDeadline();
};

class ApplicationList {
    private:
        Application* applicationList[MAX_NUMBER];
        int index;

    public:
        ApplicationList():index(0) {};
        void addNewApplication(string, string, int, string, int, string);
        ApplicationData cancelApplication(string, int);
        vector<Application*> getApplications(string);
        vector<Application*> getApplications(int);
};

class Member {
    private:
        int type;
        string id;
        string name;
        string password;

    public:
        void setType(int);
        void setId(string);
        void setName(string);
        void setPassword(string);
        virtual void setIdentificationCode(int) = 0;
        string getId();
        string getName();
        string getPassword();
        int getType();
        virtual int getIdentificationCode() = 0;
};

class CompanyMember: public Member {
    private:
        int businessNumber;

    public:
        virtual void setIdentificationCode(int businessNumber);
        virtual int getIdentificationCode();
};

class NormalMember: public Member {
    private:
        int socialSecurityNumber;
        Application* applicationList[MAX_NUMBER];

    public:
        virtual void setIdentificationCode(int socialSecurityNumber);
        virtual int getIdentificationCode();
};

class MemberList {
    private:
        Member *memberList[MAX_NUMBER];
        int index;

    public:
        MemberList():index(0) {};
        Member* authenticateMember(string, string);
        void addNewMember(int, string, int, string, string);
        void deleteMember(string);
};

class Signup {
    public:
        Signup();
        void addNewMember(int, string, int, string, string, MemberList*);
};

class SignupUI {
    private:
        int type;
        string id;
        string name;
        string password;
        int identificationCode;

    public:
        void createNewMember(Signup*);
        void showResult();
};

class Login {
    public:
        Login();
        Member* login(string, string, MemberList*);
};

class LoginUI {
    public:
        void insertInfo(Login*);
        void showResult();
};

class Logout {
    public:
        Logout();
        void logout(Member**);
};

class LogoutUI {
    private:
        string id;

    public:
        void logout(Logout*);
        void showResult();
};

class DeleteMember {
    public:
        DeleteMember();
        void deleteMember(string, MemberList*, Member**);
};

class DeleteMemberUI {
    private:
        string id;

    public:
        void withdrawal(DeleteMember*);
        void showResult();
};

class AddRecruitment {
    public:
        AddRecruitment();
        void addNewRecruitment(string, string, int, string, int, string, RecruitmentList*);
};

class AddRecruitmentUI {
    private:
        string job;
        int jobOpenning;
        string deadline;

    public:
        void createNewRecruitment(AddRecruitment*);
        void showResult();
};

class CheckRegisteredRecruitment {
    public:
        CheckRegisteredRecruitment(Member*, RecruitmentList*);
};

class CheckRegisteredRecruitmentUI {
    public:
        void showResult(vector<Recruitment*>);
};

class SearchRecruitment {
    public:
        SearchRecruitment();
        void showRecruitments(string, RecruitmentList*);
};

class SearchRecruitmentUI {
    public:
        void insertSearchValue(SearchRecruitment*);
        void showResult(vector<Recruitment*>);
};

class ApplyCompany {
    public:
        ApplyCompany();
        ApplicationData addNewApplication(int, string, RecruitmentList*, ApplicationList*);
};

class ApplyCompanyUI {
    public:
        ApplicationData selectRecruitment(ApplyCompany*);
        void showResult(string, int, string);
};

class CheckApplication {
    public:
        CheckApplication(Member*, ApplicationList*);
};

class CheckApplicationUI {
    public:
        void showResult(vector<Application*>);
};

class CancelApplication {
    public:
        CancelApplication();
        ApplicationData cancelApplication(string, int, ApplicationList*);
};

class CancelApplicationUI {
    public:
        ApplicationData cancelApplication(CancelApplication*);
        void showResult(string, int, string);
};

class CheckStatistic {
    public:
        CheckStatistic(Member*, ApplicationList*);
};

class CheckStatisticUI {
    public:
        void showResult(map<string, int>);
};
