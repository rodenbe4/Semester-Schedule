#include "dtime.h"
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

DigitalTime::DigitalTime() {
  hour = 0;
  minute = 0;
}

DigitalTime::DigitalTime(int the_hour, int the_minute) {
  if (the_hour > 23 || the_hour < 0) {
    hour = 0;
  }
  else {
    hour = the_hour;
  }

  if (the_minute > 59 || the_minute < 0) {
    minute = 0;
  }
  else {
    minute = the_minute;
  }
}

int DigitalTime::getHour() const {
  return hour;
}

int DigitalTime::getMinute() const {
  return minute;
}

void DigitalTime::set(int hour, int minute) {
  if ((hour <= 23 && hour >= 0) && (minute <= 59 && minute >= 0)) {
    this->hour = hour;
    this->minute = minute;
  }
}

bool DigitalTime::isEqual(const DigitalTime& time1) const {
  return (hour == time1.hour) && (minute == time1.minute);
}

bool DigitalTime::isLess(const DigitalTime& time1) const {
  if (isEqual(time1)) return false;
  if (hour > time1.hour) return false;
  return minute < time1.minute;
}


bool DigitalTime::input(istream& ins) {
  int oldHour = hour;
  int oldMin = minute;
  string time;

  int newHour, newMin;

  getline(ins, time, ':');
  newHour = atoi(time.c_str());
  ins >> newMin;
  set(newHour, newMin);

  return (oldHour == hour) && (oldMin == minute);
}

void DigitalTime::output(ostream& outs) const {
  if (hour < 10) {
    outs << 0;
  }
  outs << hour << ":";
  if (minute < 10) {
    outs << 0;
  }
  outs << minute;
}

istream& operator>>(istream& i, DigitalTime& d) {
  d.input(i);
  return i;
}

ostream& operator<<(ostream& o, const DigitalTime& d) {
  d.output(o);
  return o;
}



bool operator<(const DigitalTime& a, const DigitalTime& d) {
  return a.isLess(d);
}

bool operator>(const DigitalTime& a, const DigitalTime& d) {
  return !(a.isLess(d)) && !(a.isEqual(d));
}

bool operator<=(const DigitalTime& a, const DigitalTime& d) {
  return (a.isLess(d)) || (a.isEqual(d));
}

bool operator>=(const DigitalTime& a, const DigitalTime& d) {
  return !(a.isLess(d)) || (a.isEqual(d));
}

bool operator==(const DigitalTime& a, const DigitalTime& d) {
  return a.isEqual(d);
}

bool operator!=(const DigitalTime& a, const DigitalTime& d) {
  return !(a.isEqual(d));
}



/*int main() {
  DigitalTime t1;
  DigitalTime t2(10,30);
  DigitalTime t3(24,06);
  DigitalTime t4(8,60);

  cout << "t1: hour = " << t1.getHour() << ", minute = " << t1.getMinute() << endl;
  cout << "t2: hour = " << t2.getHour() << ", minute = " << t2.getMinute() << endl;
  cout << "t3: hour = " << t3.getHour() << ", minute = " << t3.getMinute() << endl;
  cout << "t4: hour = " << t4.getHour() << ", minute = " << t4.getMinute() << endl;
  t3.set(12,50);
  t4.set(24,59);
  cout << "t3: hour = " << t3.getHour() << ", minute = " << t3.getMinute() << endl;
  cout << "t4: hour = " << t4.getHour() << ", minute = " << t4.getMinute() << endl;

  if (t1 < t2) {
    cout << "t1 less than t2" << endl;
  }
  if (t1 > t2) {
    cout << "t1 greater than t2" << endl;
  }
  if (t1 <= t2) {
    cout << "t1 less than or equal to t2" << endl;
  }
  if (t1 >= t2) {
    cout << "t1 greater than or equal to t2" << endl;
  }

  t1.set(10,30);
  if (t1 == t2) {
    cout << "t1 equals t2" << endl;
  }
  if (t1 != t2) {
    cout << "t1 not equal to t2" << endl;
  }

  cout << "Enter a time: ";
  cin >> t4;

  cout << "t4: " << t4 << endl;

  return 0;
}
*/
