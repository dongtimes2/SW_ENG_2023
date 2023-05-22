// 헤더 선언
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

vector<Recruitment*> RecruitmentList::getRecuritments(string targetId) {
    int index = this->index;
    vector<Recruitment*> resultList;

    for (int i = 0; i < index; i++) {
        string id = this->recruitmentList[i]->getCompanyId();
        if (id == targetId) {
            resultList.push_back(this->recruitmentList[i]);
        }
    }

    return resultList;
};
