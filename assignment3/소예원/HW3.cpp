#include<iostream>
#include<fstream>
#include<string.h>
#include "HW3.h"

using namespace std;

void doTask();
void program_exit();//6 1

int main(void) {
    fin.open(INPUT_FILE_NAME);
    fout.open(OUTPUT_FILE_NAME);

    doTask();

    return 0;
};

void AddRecruitmentUI::createNewRecruitment(AddRecruitment* pAddRecruitment) {
    string id = pLoggedinMember->getId();
    string name = pLoggedinMember->getName();
    int businessNumber =  pLoggedinMember->getIdentificationCode();
    string job;
    int jobOpenning;
    string deadline;

    fin >> job >> jobOpenning >> deadline;

    this->job = job;
    this->jobOpenning = jobOpenning;
    this->deadline = deadline;
    pAddRecruitment->addNewRecruitment(id, name, businessNumber, job, jobOpenning, deadline, &recruitmentList);
};

void AddRecruitmentUI::showResult() {
    fout << "3.1. 채용 정보 등록" << endl;
    fout << ">" << " " << this->job << " " << this->jobOpenning << " " << this->deadline << endl;
    fout << endl;
};

void CheckRegisteredRecruitmentUI::showResult(vector<Recruitment*> resultList) {
    fout << "3.2. 등록된 채용 정보 조회" << endl;

    for (int i = 0; i < resultList.size(); i++) {
        fout << ">" << " " << resultList[i]->getJob() << " " << resultList[i]->getJobOpenning() << " " << resultList[i]->getDeadline() << endl;
    }

    fout << endl;
};

void SearchRecruitmentUI::insertSearchValue(SearchRecruitment* pSearchRecruitment) {
    string companyName;

    fin >> companyName;

    pSearchRecruitment->showRecruitments(companyName, &recruitmentList);
};

void SearchRecruitmentUI::showResult(vector<Recruitment*> resultList) {
    fout << "4.1. 채용 정보 검색" << endl;

    for (int i = 0; i < resultList.size(); i++) {
        fout << ">" << " " << resultList[i]->getCompanyName() << " " << resultList[i]->getBusinessNumber() << " " << resultList[i]->getJob() << " " << resultList[i]->getJobOpenning() << " " << resultList[i]->getDeadline() << endl;
    }

    fout << endl;
};

void doTask() {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menuLevel1 = 0;
    int menuLevel2 = 0;
    int isProgramExit = 0;

    while (!isProgramExit || !fin.eof()) {
        fin >> menuLevel1 >> menuLevel2;

        switch (menuLevel1) {
            case 1:
                
            case 2:
                
            case 3:
                switch(menuLevel2) {
                    case 1: {
                        cout << "3.1. 채용 정보 등록" << endl;
                        AddRecruitment addRecruitment;
                        break;
                    }

                    case 2: {
                        cout << "3.2. 등록된 채용 정보 조회" << endl;
                        CheckRegisteredRecruitment checkRegisteredRecruitment(pLoggedinMember, &recruitmentList);
                        break;
                    }
					
                    default:
                        break;
                }
                break;

            case 4:
                switch(menuLevel2) {
                    case 1: {
                        cout << "4.1. 채용 정보 검색" << endl;
                        SearchRecruitment searchRecruitment;
                        break;
                    }


                    default:
                        break;
                }
                break;

            case 4:
                

                    default:
                        break;
                }
                break;

            case 5:
                switch(menuLevel2) {
                    case 1: {
                        CheckStatistic checkStatistic(pLoggedinMember, &applicationList);
                        cout << "5.1. 지원 정보 통계" << endl;
                        break;
                    }

                    default:
                        break;
                }
                break;

            case 6:
                switch(menuLevel2) {
                    case 1:
                        fout << "6.1. 종료";
                        isProgramExit = 1;
                        programExit();
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
}


void programExit() {
    fin.close();
    fout.close();

    return;
};