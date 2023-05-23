// ��� ����
#include <iostream>
#include <vector>
#include "header.h"

void RecruitmentList::addNewRecruitment(string id, string name, int businessNumber, string job, int jobOpenning, string deadline) {
	int index = this->index;

	Recruitment* pRecruitment = new Recruitment();
	pRecruitment->setCompanyId(id);
	pRecruitment->setCompanyName(name);
	pRecruitment->setBusinessNumber(businessNumber);
	pRecruitment->setJob(job);
	pRecruitment->setJobOpenning(jobOpenning);
	pRecruitment->setDeadline(deadline);
	this->recruitmentList[index] = pRecruitment;
	this->index++;
};

// ȸ�� �̸����� ȸ���� ä�� ���� ����Ʈ ��ȯ
vector<Recruitment*> RecruitmentList::getRecuritments(string targetName) {
	int index = this->index;
	vector<Recruitment*> resultList;

	for (int i = 0; i < index; i++) {
		string name = this->recruitmentList[i]->getCompanyName();
		if (name == targetName) {
			resultList.push_back(this->recruitmentList[i]);
		}
	}

	return resultList;
};

// ����ڹ�ȣ�� ȸ���� ä�� ���� ����Ʈ ��ȯ
vector<Recruitment*> RecruitmentList::getRecuritments(int targetBusinessNumber) {
	int index = this->index;
	vector<Recruitment*> resultList;

	for (int i = 0; i < index; i++) {
		int businessNumber = this->recruitmentList[i]->getBusinessNumber();
		if (businessNumber == targetBusinessNumber) {
			resultList.push_back(this->recruitmentList[i]);
		}
	}

	return resultList;
};
