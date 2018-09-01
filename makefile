a.out: main.o course.o dotw.o timeInterval.o dtime.o
	g++ main.o course.o dotw.o timeInterval.o dtime.o
main.o: main.h main.cpp course.o dotw.o timeInterval.o dtime.o
	g++ -c main.cpp
course.o: course.h course.cpp dotw.o timeInterval.o dtime.o
	g++ -c course.cpp
dotw.o: dotw.h dotw.cpp timeInterval.o dtime.o
	g++ -c dotw.cpp
timeInterval.o: timeInterval.h timeInterval.cpp dtime.o
	g++ -c timeInterval.cpp
dtime.o: dtime.h dtime.cpp
	g++ -c dtime.cpp
