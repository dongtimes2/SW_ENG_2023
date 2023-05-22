// 헤더 선언
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 상수 선언
#define MAX_NUMBER 100
#define COMPANY_MEMBER 1
#define NORMAL_MEMBER 2

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
        string getJob();
        int getJobOpenning();
        string getDeadline();
        void getRecruitmentDetails();
};

class RecruitmentList {
    private:
        Recruitment* recruitmentList[MAX_NUMBER];
        int index;

    public:
        RecruitmentList():index(0) {};
        void addNewRecruitment(string, string, int, string, int, string);
        vector<Recruitment*> getRecuritments(string);
};

class Application {
    private:
        string companyId;
        string companyName;
        int companyBusinessNumber;
        string normalMemberId;
        string job;
        int jobOpenning;
        string deadline;

    public:
        void getApplicationDetails(string);
        void cancelApplication();
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
        void addNewRecruitment();
        void listRecruitments();
        virtual void setIdentificationCode(int businessNumber);
        virtual int getIdentificationCode();
};

class NormalMember: public Member {
    private:
        int socialSecurityNumber;
        Application* applicationList[MAX_NUMBER];

    public:
        void addNewApplication();
        void listApplication();
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
    private:

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
    private:
        //

    public:
        CheckRegisteredRecruitment(Member*, RecruitmentList*);
};

class CheckRegisteredRecruitmentUI {
    private:
        //

    public:
        showResult();
};

class CompanyStat {
    private:
        string companyName;
        int totalApplicant;
        string job;

    public:
        int countApplication();
};

class NormalMemberStat {
    private:
        int totalApplication;
        string applicationJob;

    public:
        int countApplication();
};

class CheckApplication {
    private:
        //

    public:
        CheckApplication();
};

class CheckApplicationUI {
    public:
};

class CancelApplication {
    private:
        //

    public:
        CancelApplication();
        void cancelApplication();
};

class ApplyCompany {
    private:
        //

    public:
        ApplyCompany();
        void addNewApplication();
};
