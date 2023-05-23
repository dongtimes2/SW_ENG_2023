// 헤더 선언
#include <iostream>
#include "header.h"

void Application::setNormalMemberId(string normalMemberId) {
	this->normalMemberId = normalMemberId;
};

void Application::setCompnayName(string companyName) {
	this->companyName = companyName;
};

void Application::setBusinessNumber(int businessNumber) {
	this->businessNumber = businessNumber;
};

void Application::setJob(string job) {
	this->job = job;
};

void Application::setJobOpenning(int jobOpenning) {
	this->jobOpenning = jobOpenning;
};

void Application::setDeadline(string deadline) {
	this->deadline = deadline;
};

string Application::getNormalMemberId() {
	return this->normalMemberId;
};

string Application::getCompanyName() {
	return this->companyName;
};

int Application::getBusinessNumber() {
	return this->businessNumber;
};

string Application::getJob() {
	return this->job;
};

int Application::getJobOpenning() {
	return this->jobOpenning;
};

string Application::getDeadline() {
	return this->deadline;
};
