CC = g++ -Wall

all: test.out manual_test.out auto_test.out

test.out: test.o schedule.o view.o
	$(CC) test.o schedule.o view.o -o test.out

manual_test.out: manual_test.o schedule.o view.o
	$(CC) manual_test.o schedule.o view.o -o manual_test.out

auto_test.out: auto_test.o schedule.o view.o
	$(CC) auto_test.o schedule.o view.o -o auto_test.out

test.o: test.cpp
	$(CC) -c test.cpp

manual_test.o: manual_test.cpp
	$(CC) -c manual_test.cpp

auto_test.o: auto_test.cpp
	$(CC) -c auto_test.cpp

schedule.o: schedule.cpp
	$(CC) -c schedule.cpp

view.o: view.cpp
	$(CC) -c view.cpp

test.cpp: test.hpp
schedule.cpp: schedule.hpp
manual_test.cpp: manual_test.hpp
auto_test.cpp: auto_test.hpp
view.cpp: view.hpp
