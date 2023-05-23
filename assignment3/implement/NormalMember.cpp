// 헤더 선언
#include <iostream>
#include "header.h"

void NormalMember::setIdentificationCode(int socialSecurityNumber) {
    this->socialSecurityNumber = socialSecurityNumber;
};

int NormalMember::getIdentificationCode() {
    return this->socialSecurityNumber;
};
