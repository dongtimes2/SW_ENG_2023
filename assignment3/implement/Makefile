CC = g++

run: Application.o Member.o NormalMember.o control.o main.o
	${CC} -o run Application.o Member.o NormalMember.o control.o main.o

Application.o: Application.cpp
	${CC} -c -o Application.o Application.cpp

Member.o: Member.cpp
	${CC} -c -o Member.o Member.cpp

NormalMember.o: NormalMember.cpp
	${CC} -c -o NormalMember.o NormalMember.cpp

control.o: control.cpp
	${CC} -c -o control.o control.cpp

main.o: main.cpp
	${CC} -c -o main.o main.cpp