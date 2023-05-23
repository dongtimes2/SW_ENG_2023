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

// 
class CompanyMember: public Member {
    private:
        int businessNumber;

    public:
        void addNewRecruitment();
        void listRecruitments();
        virtual void setIdentificationCode(int businessNumber);
        virtual int getIdentificationCode();
};

class Recruitment {
private:
	//int business_number;
	char job[MAX_STRING + 1];
	char deadline[MAX_STRING + 1];
	int total_applicant;
	int business_number;
	char company_member_id[MAX_STRING + 1];
	char company_name[MAX_STRING + 1];

public:
	bool check = 0; // 채용정보(Recruitment가 비어있는지 확인)

	void addRecruitInfo(const char*str_member_id, const char* str_job, int applicant, const char* str_deadline) {

		strcpy_s(company_member_id, MAX_STRING + 1, str_member_id);
		strcpy_s(job, MAX_STRING + 1, str_job);
		strcpy_s(deadline, MAX_STRING + 1, str_deadline);
		total_applicant = applicant;
		check = 1;
	}

	int getlistRecruitment(const char* str_member_id, int num, char* str_job, int* applicant, char*str_deadline) {

		if (strcmp(company_member_id, str_member_id) == 0)
		{
			strcpy_s(str_job, MAX_STRING + 1, job);
			*applicant = total_applicant;
			strcpy_s(str_deadline, MAX_STRING + 1, deadline);
			num++;
		}
		return num;
	}

	int getRecruitmentDetails(char* str_company_name, int num, int* business_num, char* str_job, int * applicant, char* str_deadline)
	{
		if (strcmp(company_name, str_company_name) == 0) {
			
			strcpy_s(str_company_name, MAX_STRING + 1, company_name);
			strcpy_s(str_job, MAX_STRING + 1, job);
			strcpy_s(str_deadline, MAX_STRING + 1, deadline);
			*business_num = business_number;
			*applicant = total_applicant;
			num++;
		}

		return num;
	};
};

Recruitment Recruits[MAX_NUBMER];
char user[MAX_STRING + 1] = ""; // 현재 사용중인 유저
int index; // 검색용 인덱스
class CompanyMember {
private:
	int business_number;

public:

};

// 3.1. 채용 정보 등록
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
/*class AddRecruitmentUI {

public:
	char job[MAX_STRING];
	int total_applicant = 0;
	char deadline[MAX_STRING];

	void startInterface() {
		fprintf_s(out_fp, "3.1. 채용 정보 등록\n");
		fprintf_s(out_fp, "> %s %d %s\n", job, total_applicant, deadline);
	}

	void createNewRecruitment() {
		fscanf_s(in_fp, "%s %d %s", job, sizeof(job), &total_applicant, deadline, sizeof(deadline));
	}

};



class AddRecruitment {

public:
	void addNewRecruitment()
	{
		AddRecruitmentUI addRecruitmentUI;
		addRecruitmentUI.createNewRecruitment();

		for (int i = 0; i < MAX_NUBMER; i++)
		{
			if (Recruits[i].check == 0)
			{
				Recruits[i].addRecruitInfo(user, addRecruitmentUI.job, addRecruitmentUI.total_applicant, addRecruitmentUI.deadline);
				break;
			}
		}
		addRecruitmentUI.startInterface();
	}
};*/

// 3.2. 등록된 채용정보 조회
class CheckRegisteredRecruitment {
    public:
        CheckRegisteredRecruitment(Member*, RecruitmentList*);
};

class CheckRegisteredRecruitmentUI {
    public:
        void showResult(vector<Recruitment*>);
};

/*class CheckRegisteredRecruitmentUI {

public:

	char job[MAX_NUBMER][MAX_STRING + 1];
	char deadline[MAX_NUBMER][MAX_STRING + 1];
	int total_applicant[MAX_NUBMER];

	void startInterface(int num)
	{
		fprintf_s(out_fp, "3.2. 등록된 채용 정보 조회\n");
		for (int i = 0; i < num; i++)
			fprintf_s(out_fp, "> { %s %d %s }\n", job[i], total_applicant[i], deadline[i]);
	}

};

class CheckRegisteredRecruitment {

public:
	void getRegisteredRecruitment()
	{
		CheckRegisteredRecruitmentUI registeredRecruitmentUI;
		int num = 0;
		for (int i = 0; i < MAX_NUBMER; i++)
		{
			num = Recruits[i].getlistRecruitment(user, num, registeredRecruitmentUI.job[num], &registeredRecruitmentUI.total_applicant[num], registeredRecruitmentUI.deadline[num]);
		}

		registeredRecruitmentUI.startInterface(num);
	}

};*/

// 4.1. 채용 정보 검색
class SearchRecruitmentUI {

public:
	char company_name[MAX_STRING];

	void insertSearchValue() {
		fscanf_s(in_fp, "%s", company_name, sizeof(company_name));
	}

	void startInterface(char* company_member_id, char* company_name, int business_number, char* job, int total_applicant, char* deadline) {
		fprintf_s(out_fp, "4.1. 채용 정보 검색\n");
		fprintf_s(out_fp, "> %s %d %s %d %s\n", company_member_id, company_name, business_number, job, total_applicant, deadline);
	}
};

class SearchRecruitment {

public:
	char company_member_id[MAX_STRING + 1];
	char company_name[MAX_STRING + 1];
	int business_number;
	char job[MAX_STRING + 1];
	int total_applicant;
	char deadline[MAX_STRING + 1];

	void showRecruitments()
	{
		SearchRecruitmentUI searchRecruitmentUI;
		if (strcmp(user, "") != 0)
		{
			searchRecruitmentUI.insertSearchValue();
			int num = 0;

			for (int i = 0; i < MAX_NUBMER; i++)
			{
				// char* str_company_name, int num, int* business_num, char* str_job, int * applicant, char* str_deadline
				num = Recruits[i].getRecruitmentDetails(searchRecruitmentUI.company_name, num, &business_number, job, &total_applicant, deadline);
				index = i;
				if (num != 0)
					break;
			}
			// char* company_member_id, char* company_name, int business_number, char* job, int total_applicant, char* deadline
			searchRecruitmentUI.startInterface(company_member_id, company_name, business_number, job, total_applicant, deadline);
		}
	}
};

