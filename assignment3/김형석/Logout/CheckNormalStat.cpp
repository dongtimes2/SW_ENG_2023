#include <iostream>
#include "CheckCompanyStatUI.h"
#include "CheckCompnayStat.h"
#include "header.h"

using namespace std;


void CheckCompanyStatUI::startInterface(CompanyMember* member) {
    listRecuritment = member->listRecruitments();
    recuritmentDetails = listRecuritment->getRecruitmentDetails();
    applicationDetails = recuritmentDetails->getApplicationDetails();
    cout << "5.1 지원 정보 통계" << endl;
    cout << <<"{ "<<applicationDetails->countApplicant() << " }" << endl;
};



