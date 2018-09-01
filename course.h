#include "dotw.h"
#include "timeInterval.h"
#include <iostream>
using namespace std;

class Course {

public:
  // Constructors
  Course();
  Course(string name);
  Course(string name, string sect);
  Course(const Course& c);
  Course(string name, string sect, DaysOfTheWeek& days, TimeInterval& t, string instr);

  // Getter methods
  string getCourseName() const;
  string getSection() const;
  DaysOfTheWeek getDaysMet() const;
  TimeInterval getTime() const;
  string getInstructor() const;

  // Setter methods
  void setCourseName(string name);
  void setSection(string sect);
  void setDaysMet(string days);
  void setTime(DigitalTime& start, DigitalTime& end);
  void setInstructor(string instr);

  // Other methods
  bool isOverlap(const Course& c) const;
  bool isMatch(const Course& c) const;
  void output(ostream& outs) const;

private:
  string courseName;
  string section;
  DaysOfTheWeek classDays;
  TimeInterval time;
  string instructor;
};


// Operator overload
bool operator&&(const Course& a, const Course& b);
bool operator==(const Course& a, const Course& b);
ostream& operator<<(ostream& o, const Course& c);
