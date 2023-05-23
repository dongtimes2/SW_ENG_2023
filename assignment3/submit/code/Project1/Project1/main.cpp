// ��� ����
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include "header.h"
using namespace std;

// ��� ����
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void programExit();

// ���� ����
ifstream fin;
ofstream fout;
Member* pLoggedinMember;
MemberList memberList;
RecruitmentList recruitmentList;
ApplicationList applicationList;

// �ٿ���� Ŭ���� ����
void SignupUI::createNewMember(Signup* pSignup) {
	int type;
	string name;
	int identificationCode;
	string id;
	string password;

	fin >> type >> name >> identificationCode >> id >> password;

	this->type = type;
	this->id = id;
	this->name = name;
	this->password = password;
	this->identificationCode = identificationCode;
	pSignup->addNewMember(type, name, identificationCode, id, password, &memberList);
};

void SignupUI::showResult() {
	fout << "1.1. ȸ������" << endl;
	fout << ">" << " " << this->type << " " << this->name << " " << this->identificationCode << " " << this->id << " " << this->password << endl;
	fout << endl;
};

void DeleteMemberUI::withdrawal(DeleteMember* pDeleteMember) {
	this->id = pLoggedinMember->getId();
	pDeleteMember->deleteMember(pLoggedinMember->getId(), &memberList, &pLoggedinMember);
};

void DeleteMemberUI::showResult() {
	fout << "1.2. ȸ��Ż��" << endl;
	fout << ">" << " " << this->id << endl;
	fout << endl;
};

void LoginUI::insertInfo(Login* pLogin) {
	string id;
	string password;

	fin >> id >> password;

	pLoggedinMember = pLogin->login(id, password, &memberList);
};

void LoginUI::showResult() {
	fout << "2.1. �α���" << endl;
	fout << ">" << " " << pLoggedinMember->getId() << " " << pLoggedinMember->getPassword() << endl;
	fout << endl;
};

void LogoutUI::logout(Logout* pLogout) {
	this->id = pLoggedinMember->getId();
	pLogout->logout(&pLoggedinMember);
};

void LogoutUI::showResult() {
	fout << "2.2. �α׾ƿ�" << endl;
	fout << ">" << " " << this->id << endl;
	fout << endl;
};

void AddRecruitmentUI::createNewRecruitment(AddRecruitment* pAddRecruitment) {
	string id = pLoggedinMember->getId();
	string name = pLoggedinMember->getName();
	int businessNumber = pLoggedinMember->getIdentificationCode();
	string job;
	int jobOpenning;
	string deadline;

	fin >> job >> jobOpenning >> deadline;

	this->job = job;
	this->jobOpenning = jobOpenning;
	this->deadline = deadline;
	pAddRecruitment->addNewRecruitment(id, name, businessNumber, job, jobOpenning, deadline, &recruitmentList);
};

void AddRecruitmentUI::showResult() {
	fout << "3.1. ä�� ���� ���" << endl;
	fout << ">" << " " << this->job << " " << this->jobOpenning << " " << this->deadline << endl;
	fout << endl;
};

void CheckRegisteredRecruitmentUI::showResult(vector<Recruitment*> resultList) {
	fout << "3.2. ��ϵ� ä�� ���� ��ȸ" << endl;

	for (int i = 0; i < resultList.size(); i++) {
		fout << ">" << " " << resultList[i]->getJob() << " " << resultList[i]->getJobOpenning() << " " << resultList[i]->getDeadline() << endl;
	}

	fout << endl;
};

void SearchRecruitmentUI::insertSearchValue(SearchRecruitment* pSearchRecruitment) {
	string companyName;

	fin >> companyName;

	pSearchRecruitment->showRecruitments(companyName, &recruitmentList);
};

void SearchRecruitmentUI::showResult(vector<Recruitment*> resultList) {
	fout << "4.1. ä�� ���� �˻�" << endl;

	for (int i = 0; i < resultList.size(); i++) {
		fout << ">" << " " << resultList[i]->getCompanyName() << " " << resultList[i]->getBusinessNumber() << " " << resultList[i]->getJob() << " " << resultList[i]->getJobOpenning() << " " << resultList[i]->getDeadline() << endl;
	}

	fout << endl;
};

ApplicationData ApplyCompanyUI::selectRecruitment(ApplyCompany* pApplyCompany) {
	string normalMemberid = pLoggedinMember->getId();
	int businessNumber;

	fin >> businessNumber;

	ApplicationData resultData = pApplyCompany->addNewApplication(businessNumber, normalMemberid, &recruitmentList, &applicationList);

	return resultData;
};

void ApplyCompanyUI::showResult(string companyName, int businessNumber, string job) {
	fout << "4.2. ä�� ����" << endl;
	fout << ">" << " " << companyName << " " << businessNumber << " " << job << endl;
	fout << endl;
};

bool compare1(Application* a, Application* b) {
	return a->getCompanyName() < b->getCompanyName();
};

void CheckApplicationUI::showResult(vector<Application*> resultList) {
	fout << "4.3. ���� ���� ��ȸ" << endl;

	sort(resultList.begin(), resultList.end(), compare1);

	for (int i = 0; i < resultList.size(); i++) {
		fout << ">" << " " << resultList[i]->getCompanyName() << " " << resultList[i]->getBusinessNumber() << " " << resultList[i]->getJob() << " " << resultList[i]->getJobOpenning() << " " << resultList[i]->getDeadline() << endl;
	}

	fout << endl;
};

ApplicationData CancelApplicationUI::cancelApplication(CancelApplication* pCancelApplication) {
	string normalMemberid = pLoggedinMember->getId();
	int businessNumber;

	fin >> businessNumber;

	ApplicationData resultData = pCancelApplication->cancelApplication(normalMemberid, businessNumber, &applicationList);

	return resultData;
};

void CancelApplicationUI::showResult(string companyName, int businessNumber, string job) {
	fout << "4.4. ���� ���" << endl;
	fout << ">" << " " << companyName << " " << businessNumber << " " << job << endl;
	fout << endl;
};

void CheckStatisticUI::showResult(map<string, int> resultMap) {
	fout << "5.1. ���� ���� ���" << endl;

	for (map<string, int>::iterator i = resultMap.begin(); i != resultMap.end(); i++) {
		fout << ">" << " " << i->first << " " << i->second << endl;
	}

	fout << endl;
};

int main(void) {
	fin.open(INPUT_FILE_NAME);
	fout.open(OUTPUT_FILE_NAME);

	doTask();

	return 0;
};

void doTask() {
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menuLevel1 = 0;
	int menuLevel2 = 0;
	int isProgramExit = 0;

	while (!isProgramExit || !fin.eof()) {
		fin >> menuLevel1 >> menuLevel2;

		switch (menuLevel1) {
		case 1:
			switch (menuLevel2) {
			case 1: {
				cout << "1.1. ȸ������" << endl;
				Signup signup;
				break;
			}

			case 2: {
				cout << "1.2. ȸ��Ż��" << endl;
				DeleteMember deleteMember;
				break;
			}

			default:
				break;
			}
			break;

		case 2:
			switch (menuLevel2) {
			case 1: {
				cout << "2.1. �α���" << endl;
				Login longin;
				break;
			}

			case 2: {
				cout << "2.2. �α׾ƿ�" << endl;
				Logout logout;
				break;
			}

			default:
				break;
			}
			break;

		case 3:
			switch (menuLevel2) {
			case 1: {
				cout << "3.1. ä�� ���� ���" << endl;
				AddRecruitment addRecruitment;
				break;
			}

			case 2: {
				cout << "3.2. ��ϵ� ä�� ���� ��ȸ" << endl;
				CheckRegisteredRecruitment checkRegisteredRecruitment(pLoggedinMember, &recruitmentList);
				break;
			}

			default:
				break;
			}
			break;

		case 4:
			switch (menuLevel2) {
			case 1: {
				cout << "4.1. ä�� ���� �˻�" << endl;
				SearchRecruitment searchRecruitment;
				break;
			}

			case 2: {
				cout << "4.2. ä�� ����" << endl;
				ApplyCompany applyCompany;
				break;
			}

			case 3: {
				cout << "4.3. ���� ���� ��ȸ" << endl;
				CheckApplication checkApplication(pLoggedinMember, &applicationList);
				break;
			}

			case 4: {
				CancelApplication cancelApplication;
				cout << "4.4. ���� ���" << endl;
				break;
			}

			default:
				break;
			}
			break;

		case 5:
			switch (menuLevel2) {
			case 1: {
				CheckStatistic checkStatistic(pLoggedinMember, &applicationList);
				cout << "5.1. ���� ���� ���" << endl;
				break;
			}

			default:
				break;
			}
			break;

		case 6:
			switch (menuLevel2) {
			case 1:
				fout << "6.1. ����";
				isProgramExit = 1;
				programExit();
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}
	}

	return;
};

void programExit() {
	fin.close();
	fout.close();

	return;
};
