// 헤더 선언
#include <iostream>
#include <vector>
#include "header.h"

void ApplicationList::addNewApplication(string normalMemberId, string companyName, int businessNumber, string job, int jobOpenning, string deadline) {
	int index = this->index;

	Application* pApplication = new Application();
	pApplication->setNormalMemberId(normalMemberId);
	pApplication->setCompnayName(companyName);
	pApplication->setBusinessNumber(businessNumber);
	pApplication->setJob(job);
	pApplication->setJobOpenning(jobOpenning);
	pApplication->setDeadline(deadline);
	this->applicationList[index] = pApplication;
	this->index++;
};

// 일반 멤버 이름과 일치하는 지원서 리스트 반환
vector<Application*> ApplicationList::getApplications(string targetNormalMemberId) {
	int index = this->index;
	vector<Application*> resultList;

	for (int i = 0; i < index; i++) {
		if (!this->applicationList[i]) continue;

		string normalMemberId = this->applicationList[i]->getNormalMemberId();
		if (normalMemberId == targetNormalMemberId) {
			resultList.push_back(this->applicationList[i]);
		}
	}

	return resultList;
};

// 사업자번호가 일치하는 지원서 리스트 반환
vector<Application*> ApplicationList::getApplications(int targetBusinessNumber) {
	int index = this->index;
	vector<Application*> resultList;

	for (int i = 0; i < index; i++) {
		if (!this->applicationList[i]) continue;

		int businessNumber = this->applicationList[i]->getBusinessNumber();
		if (businessNumber == targetBusinessNumber) {
			resultList.push_back(this->applicationList[i]);
		}
	}

	return resultList;
};

ApplicationData ApplicationList::cancelApplication(string targetNormalMemberId, int targetBusinessNumber) {
	int index = this->index;
	ApplicationData applicationData;
	string companyName;
	string job;

	for (int i = 0; i < index; i++) {
		if (!this->applicationList[i]) continue;

		string normalMemberId = this->applicationList[i]->getNormalMemberId();
		int businessNumber = this->applicationList[i]->getBusinessNumber();

		if (normalMemberId == targetNormalMemberId && businessNumber == targetBusinessNumber) {
			companyName = this->applicationList[i]->getCompanyName();
			job = this->applicationList[i]->getJob();
			this->applicationList[i] = NULL;
		}
	}

	applicationData.companyName = companyName;
	applicationData.job = job;
	applicationData.targetBusinessNumber = targetBusinessNumber;

	return applicationData;
};
