CC = g++ -Wall

all: test.out manual_test.out

test.out: test.o schedule.o
	$(CC) test.o schedule.o -o test.out

manual_test.out: manual_test.o schedule.o
	$(CC) manual_test.o schedule.o -o manual_test.out

test.o: test.cpp
	$(CC) -c test.cpp

manual_test.o: manual_test.cpp
	$(CC) -c manual_test.cpp

schedule.o: schedule.cpp
	$(CC) -c schedule.cpp

test.cpp: test.hpp
schedule.cpp: schedule.hpp
manual_test.cpp: manual_test.hpp
