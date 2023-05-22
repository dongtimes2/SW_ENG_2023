// 헤더 선언
#include <iostream>
#include "header.h"

void CompanyMember::setIdentificationCode(int businessNumber) {
    this->businessNumber = businessNumber;
};

int CompanyMember::getIdentificationCode() {
    return this->businessNumber;
};
