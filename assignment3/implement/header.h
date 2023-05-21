// 헤더 선언
#pragma once
#include <iostream>
using namespace std;

// 상수 선언
#define MAX_NUMBER 100

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
};

class CompanyMember:Member {
    private:
        string businessNumber;

    public:
        void addNewRecruitment();
        void listRecruitments();
};

class NormalMember:Member {
    private:
        string socialSecurityNumber;
        Application* applicationList[MAX_NUMBER];

    public:
        void addNewApplication();
        void listApplication();
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
        void startInterface();
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
