// 헤더 선언
#include <iostream>
#include <string>
#include <fstream>
#include "header.h"
using namespace std;

// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void programExit();

// 변수 선언
ifstream fin;
ofstream fout;

int main(void) {
    fin.open(INPUT_FILE_NAME);
    fout.open(OUTPUT_FILE_NAME);

    doTask();

    return 0;
}

void doTask() {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menuLevel1 = 0;
    int menuLevel2 = 0;
    int isProgramExit = 0;

    while (!isProgramExit || !fin.eof()) {
        fin >> menuLevel1 >> menuLevel2;

        switch (menuLevel1) {
            case 1:
                switch(menuLevel2) {
                    case 1:
                        cout << "1.1. 회원가입" << endl;
                        break;

                    case 2:
                        cout << "1.2. 회원탈퇴" << endl;
                        break;

                    default:
                        break;
                }
                break;

            case 2:
                switch(menuLevel2) {
                    case 1:
                        cout << "2.1. 로그인" << endl;
                        break;

                    case 2:
                        cout << "2.2. 로그아웃" << endl;
                        break;

                    default:
                        break;
                }
                break;

            case 3:
                switch(menuLevel2) {
                    case 1:
                        cout << "3.1. 채용 정보 등록" << endl;
                        break;

                    case 2:
                        cout << "3.2. 등록된 채용 정보 조회" << endl;
                        break;

                    default:
                        break;
                }
                break;

            case 4:
                switch(menuLevel2) {
                    case 1:
                        cout << "4.1. 채용 정보 검색" << endl;
                        break;

                    case 2:
                        cout << "4.2. 채용 지원" << endl;
                        break;

                    case 3:
                        cout << "4.3. 지원 정보 조회" << endl;
                        break;

                    case 4:
                        cout << "4.4. 지원 취소" << endl;
                        break;

                    default:
                        break;
                }
                break;

            case 5:
                switch(menuLevel2) {
                    case 1:
                        cout << "5.1. 지원 정보 통계" << endl;
                        break;

                    default:
                        break;
                }
                break;

            case 6:
                switch(menuLevel2) {
                    case 1:
                        fout << "6.1. 종료" << endl;
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

    return;
}

void programExit() {
    fin.close();
    fout.close();

    return;
}