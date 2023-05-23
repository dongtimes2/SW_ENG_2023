CC = g++
OUTPUT_DIR = ./test

build: clean Application.o ApplicationList.o Member.o CompanyMember.o NormalMember.o MemberList.o Recruitment.o RecruitmentList.o control.o main.o
	${CC} -o run Application.o ApplicationList.o Member.o CompanyMember.o NormalMember.o MemberList.o Recruitment.o RecruitmentList.o control.o main.o

test: run
	./run

diff:
	diff output.txt demo_output.txt

Application.o: Application.cpp
	${CC} -c -o Application.o Application.cpp

ApplicationList.o: ApplicationList.cpp
	${CC} -c -o ApplicationList.o ApplicationList.cpp

Member.o: Member.cpp
	${CC} -c -o Member.o Member.cpp

CompanyMember.o: CompanyMember.cpp
	${CC} -c -o CompanyMember.o CompanyMember.cpp

NormalMember.o: NormalMember.cpp
	${CC} -c -o NormalMember.o NormalMember.cpp

MemberList.o: MemberList.cpp
	${CC} -c -o MemberList.o MemberList.cpp

Recruitment.o: Recruitment.cpp
	${CC} -c -o Recruitment.o Recruitment.cpp

RecruitmentList.o: RecruitmentList.cpp
	${CC} -c -o RecruitmentList.o RecruitmentList.cpp

control.o: control.cpp
	${CC} -c -o control.o control.cpp

main.o: main.cpp
	${CC} -c -o main.o main.cpp

clean:
	rm -rf *.o

