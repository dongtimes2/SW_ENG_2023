// 헤더 선언
#include <iostream>
#include "header.h"

void Recruitment::setCompanyId(string id) {
    this->companyId = id;
};

void Recruitment::setCompanyName(string name) {
    this->companyName = name;
};

void Recruitment::setBusinessNumber(int businessNumber) {
    this->businessNumber = businessNumber;
};

void Recruitment::setJob(string job) {
    this->job = job;
};

void Recruitment::setJobOpenning(int jobOpenning) {
    this->jobOpenning = jobOpenning;
};

void Recruitment::setDeadline(string deadline) {
    this->deadline = deadline;
};

string Recruitment::getCompanyId() {
    return this->companyId;
};

string Recruitment::getJob() {
    return this->job;
};

int Recruitment::getJobOpenning() {
    return this->jobOpenning;
};

string Recruitment::getDeadline() {
    return this->deadline;
};
