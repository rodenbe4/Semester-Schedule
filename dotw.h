#ifndef DOTW
#define DOTW

//#include "timeInterval.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class DaysOfTheWeek {

public:
  DaysOfTheWeek();
  DaysOfTheWeek(string days);

  void setDays(string days);
  string getDays() const;

  void input(istream& ins);
  void output(ostream& outs) const;

  bool isEqual(const DaysOfTheWeek& d) const;
  bool isOverlap(const DaysOfTheWeek& d) const;

private:
  bool daysMet[6];
  bool isOnline;
  void initializeArray();
};

bool operator&&(const DaysOfTheWeek& a, const DaysOfTheWeek& b);
bool operator==(const DaysOfTheWeek& a, const DaysOfTheWeek& b);
bool operator!=(const DaysOfTheWeek& a, const DaysOfTheWeek& b);
istream& operator>>(istream& i, DaysOfTheWeek& d);
ostream& operator<<(ostream& o, const DaysOfTheWeek& d);

#endif
