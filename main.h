#ifndef MAIN
#define MAIN

#include "course.h"
#include <fstream>
#include <sstream>

bool validateSchedule(Course schedule[]);
string addCourse(Course schedule[], DaysOfTheWeek& days, DigitalTime& start, DigitalTime& end, string name, string section, string instructor);
bool exportSchedule(Course schedule[], string filename);
bool importSchedule(Course schedule[], string filename);
int main();

#endif
