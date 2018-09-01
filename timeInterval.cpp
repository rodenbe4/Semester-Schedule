#include "timeInterval.h"

TimeInterval::TimeInterval() {
  startTime.set(0,0);
  endTime.set(0,0);
}

TimeInterval::TimeInterval(const DigitalTime& a, const DigitalTime& b) {
  if (b < a) {
    startTime.set(0,0);
    endTime.set(0,0);
  }
  else {
    startTime = a;
    endTime = b;
  }
}

DigitalTime TimeInterval::getStart() const {
  return startTime;
}

DigitalTime TimeInterval::getEnd() const {
  return endTime;
}

void TimeInterval::setInterval(const DigitalTime& a, const DigitalTime& b) {
  if (a <= b) {
    startTime = a;
    endTime = b;
  }
}

void TimeInterval::output(ostream& outs) const {
  outs << startTime << " - " << endTime;
}

bool operator&&(const TimeInterval& a, const TimeInterval& b) {
  if (a.getStart() == b.getStart()) {
    return true;
  }
  if ((a.getStart() == b.getEnd()) || (a.getEnd() == b.getStart())) {
    return true;
  }
  if ((a.getStart() < b.getStart())  && (a.getEnd() > b.getStart())) {
    return true;
  }
  if ((a.getStart() > b.getStart()) && (a.getStart() < b.getEnd())) {
    return true;
  }
  return false;
}

ostream& operator<<(ostream& outs, const TimeInterval& d) {
  d.output(outs);
  return outs;
}
/*
int main() {
  DigitalTime d1(9,30);
  DigitalTime d2(10,45);
  TimeInterval t1;
  TimeInterval t2(d1, d2);

  cout << "t1: " << t1 << endl;
  cout << "t2: " << t2 << endl;

  t1.setInterval(d2,d1);
  cout << "t1: " << t1 << endl;

  d1.set(10,0);
  d2.set(11,50);
  t1.setInterval(d1,d2);
  cout << "t1: " << t1 << endl;

  cout << "Do t1 and t2 overlap?" << endl;
  cout << (t1 && t2) << endl;
  return 0;
}
*/
