#include "dotw.h"

DaysOfTheWeek::DaysOfTheWeek() {
  initializeArray();
  isOnline = true;
}

DaysOfTheWeek::DaysOfTheWeek(string days) {
  setDays(days);
}

void DaysOfTheWeek::initializeArray() {
  for (int i = 0; i < 6; i++) {
    daysMet[i] = false;
  }
}

string DaysOfTheWeek::getDays() const {
  if (isOnline) {
    return "O";
  }
  else {
    string days = "";
    if (daysMet[0]) {
      days.append("M");
    }
    if (daysMet[1]) {
      days.append("T");
    }
    if (daysMet[2]) {
      days.append("W");
    }
    if (daysMet[3]) {
      days.append("R");
    }
    if (daysMet[4]) {
      days.append("F");
    }
    if (daysMet[5]) {
      days.append("S");
    }
    return days;
  }
}

void DaysOfTheWeek::setDays(string days) {
  initializeArray();
  isOnline = true;
  for (int i = 0; i < 6; i++) {
    if (days[i] == 'M' || days[i] == 'm') {
      daysMet[0] = true;
      isOnline = false;
    }
    else if (days[i] == 'T' || days[i] == 't') {
      daysMet[1] = true;
      isOnline = false;
    }
    else if (days[i] == 'W' || days[i] == 'w') {
      daysMet[2] = true;
      isOnline = false;
    }
    else if (days[i] == 'R' || days[i] == 'r') {
      daysMet[3] = true;
      isOnline = false;
    }
    else if (days[i] == 'F' || days[i] == 'f') {
      daysMet[4] = true;
      isOnline = false;
    }
    else if (days[i] == 'S' || days[i] == 's') {
      daysMet[5] = true;
      isOnline = false;
    }
  }
}

bool DaysOfTheWeek::isEqual(const DaysOfTheWeek& d) const {
  for (int i = 0; i < 6; i++) {
    if (this->daysMet[i] != d.daysMet[i]) {
      return false;
    }
  }
  return true;
}

bool DaysOfTheWeek::isOverlap(const DaysOfTheWeek& d) const {
  for (int i = 0; i < 6; i++) {
    if ((this->daysMet[i] == true) && (d.daysMet[i] == true)) {
      return true;
    }
  }
  return false;
}

void DaysOfTheWeek::input(istream& ins) {
  string days;
  ins >> days;
  setDays(days);
}

void DaysOfTheWeek::output(ostream& outs) const {
  outs << getDays();
}


bool operator&&(const DaysOfTheWeek& a, const DaysOfTheWeek& b) {
  return a.isOverlap(b);
}

bool operator==(const DaysOfTheWeek& a, const DaysOfTheWeek& b) {
  return a.isEqual(b);
}

bool operator!=(const DaysOfTheWeek& a, const DaysOfTheWeek& b) {
  return !(a.isEqual(b));
}

istream& operator>>(istream& i, DaysOfTheWeek& d) {
  d.input(i);
  return i;
}

ostream& operator<<(ostream& o, const DaysOfTheWeek& d) {
  d.output(o);
  return o;
}



/*int main() {
  DaysOfTheWeek d1;
  DaysOfTheWeek d2("MWF");
  cout << "Days met: " <<  d1.getDays() << endl;
  cout << "Days met: " <<  d2.getDays() << endl;
  DaysOfTheWeek d3;
  d3.setDays("WF");
  cout << "Days met: " << d3.getDays() << endl;
  cout << "Is d1 = d2?" << endl;
  if (d1 == d2) {
    cout << "yes" << endl;
  }
  else if (d1 != d2) {
    cout << "no" << endl;
  }

  cout << "Is d2 = d3?" << endl;
  if (d2 == d3) {
    cout << "yes" << endl;
  }
  else if (d2 != d3) {
    cout << "no" << endl;
  }

  cout << "Does d1 overlap with d2?" << endl;
  if (d1 && d2) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
  cout << "Does d2 overlap with d3?" << endl;
  if (d2 && d3) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }

  DaysOfTheWeek d4;
  cout << "Enter in the days the course meets: ";
  cin >> d4;
  cout << "Days met: " << d4 << endl;
  return 0;
}
*/
