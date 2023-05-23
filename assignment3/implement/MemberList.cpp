// 헤더 선언
#include <iostream>
#include "header.h"

void MemberList::addNewMember(int type, string name, int identificationCode, string id, string password) {
    int index = this->index;

    if (type == COMPANY_MEMBER) {
        Member* pMember = new CompanyMember();
        pMember->setType(type);
        pMember->setId(id);
        pMember->setName(name);
        pMember->setPassword(password);
        pMember->setIdentificationCode(identificationCode);
        this->memberList[index] = pMember;
    } else if (type == NORMAL_MEMBER) {
        Member* pMember = new NormalMember();
        pMember->setType(type);
        pMember->setId(id);
        pMember->setName(name);
        pMember->setPassword(password);
        pMember->setIdentificationCode(identificationCode);
        this->memberList[index] = pMember;
    }

    this->index++;
};

Member* MemberList::authenticateMember(string targetId, string targetPassword) {
    int index = this->index;

    for (int i = 0; i < index; i++) {
        if (!this->memberList[i]) continue;

        string id = this->memberList[i]->getId();
        string password = this->memberList[i]->getPassword();

        if (id == targetId && password == targetPassword) {
            return this->memberList[i];
        }
    }

    return NULL;
};

void MemberList::deleteMember(string targetId) {
    int index = this->index;

    for (int i = 0; i < index; i++) {
        if (!this->memberList[i]) continue;

        string id = this->memberList[i]->getId();

        if (id == targetId) {
            this->memberList[i] = NULL;
        }
    }
};
