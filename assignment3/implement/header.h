#include <iostream>
using namespace std;

#define TEMP_NUMBER 100

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

    public:
        void addNewApplication();
        void listApplication();
        void deleteApplication();
};

class Recruitment {
    private:
        string companyName;
        string job;
        int jobOpenning;
        string deadline;

    public:
        void getRecruitmentDetails();
};

class Application {
    private:
        string companyName;
        string job;
        int jobOpenning;
        string deadline;

    public:
        void getApplicationDetails();
        void cancelApplication();
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