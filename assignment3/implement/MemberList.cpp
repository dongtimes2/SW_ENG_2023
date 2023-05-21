#include "header.h"

void MemberList::addNewMember(int type, string name, int identificationCode, string id, string password) {
    int index = this->index;

    if (type == COMPANY_MEMBER) {
        Member* pMember = new CompanyMember();
        pMember->setId(id);
        pMember->setName(name);
        pMember->setPassword(password);
        pMember->setIdentificationCode(identificationCode);
        this->memberList[index] = pMember;
    } else if (type == NORMAL_MEMBER) {
        Member* pMember = new NormalMember();
        pMember->setId(id);
        pMember->setName(name);
        pMember->setPassword(password);
        pMember->setIdentificationCode(identificationCode);
    }

    this->index++;
};
