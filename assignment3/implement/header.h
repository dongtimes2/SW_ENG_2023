// 헤더 선언
#pragma once
#include <iostream>
#include <string>
using namespace std;

// 상수 선언
#define MAX_NUMBER 100
#define COMPANY_MEMBER 1
#define NORMAL_MEMBER 2

class Application {
    private:
        string companyId;
        string companyName;
        string companyBusinessNumber;
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
        string id;
        string name;
        string password;

    public:
        bool authenticateMember();
        void deleteMember();
        void setId(string);
        void setName(string);
        void setPassword(string);
        string getName();
        virtual void setIdentificationCode(int) = 0;
};

class CompanyMember: public Member {
    private:
        int businessNumber;

    public:
        void addNewRecruitment();
        void listRecruitments();
        virtual void setIdentificationCode(int businessNumber) {
            this->businessNumber = businessNumber;
        }
};

class NormalMember: public Member {
    private:
        int socialSecurityNumber;
        Application* applicationList[MAX_NUMBER];

    public:
        void addNewApplication();
        void listApplication();
        virtual void setIdentificationCode(int socialSecurityNumber) {
            this->socialSecurityNumber = socialSecurityNumber;
        }
};

class MemberList {
    private:
        Member *memberList[MAX_NUMBER];
        int index = 0;

    public:
        void addNewMember(int, string, int, string, string);
};

class Recruitment {
    private:
        string companyId;
        string companyName;
        string companyBusinessNumber;
        string normalMemberId;
        string job;
        int jobOpenning;
        string deadline;

    public:
        void getRecruitmentDetails();
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

class Signup {
    private:

    public:
        Signup();
        void addNewMember(int, string, int, string, string, MemberList*);
};

class SignupUI {
    private:

    public:
        void createNewMember(Signup*);
};
