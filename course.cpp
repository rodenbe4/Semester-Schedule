#include "course.h"

Course::Course() {
  courseName = "Course Name";
  section = "000";
  instructor = "Instructor";
}

Course::Course(string name) {
  courseName = name;
}

Course::Course(string name, string sect) {
  courseName = name;
  section = sect;
  instructor = "Instructor";
}

Course::Course(string name, string sect, DaysOfTheWeek& days, TimeInterval& t, string instr) {
  courseName = name;
  section = sect;
  classDays = days;
  time = t;
  instructor = instr;
}

Course::Course(const Course& c) {
  this->courseName = c.courseName;
  this->section = c.section;
  this->classDays = c.classDays;
  this->time = c.time;
  this->instructor = c.instructor;
}

string Course::getCourseName() const {
  return courseName;
}

string Course::getSection() const {
  return section;
}

DaysOfTheWeek Course::getDaysMet() const {
  return classDays;
}

TimeInterval Course::getTime() const {
  return time;
}

string Course::getInstructor() const {
  return instructor;
}

void Course::setCourseName(string name) {
  courseName = name;
}

void Course::setSection(string sect) {
  section = sect;
}

void Course::setDaysMet(string days) {
  classDays.setDays(days);
}

void Course::setTime(DigitalTime& start, DigitalTime& end) {
  time.setInterval(start, end);
}

void Course::setInstructor(string instr) {
  instructor = instr;
}

bool Course::isOverlap(const Course& c) const {
  if ((this->instructor).compare(c.instructor) != 0) return false;
  return (this->time) && c.time;
}

bool Course::isMatch(const Course& c) const {
  if ((this->courseName).compare(c.courseName) != 0) return false;
  return (this->section).compare(c.section) == 0;
}

void Course::output(ostream& outs) const {
  outs << classDays << " ";
  outs << time << " ";
  outs << courseName << " ";
  outs << section << " ";
  outs << instructor;
}


bool operator&&(const Course& a, const Course& b) {
  return a.isOverlap(b);
}

bool operator==(const Course& a, const Course& b) {
  return a.isMatch(b);
}

ostream& operator<<(ostream& o, const Course& c) {
  c.output(o);
  return o;
}


/*
int main() {
  Course c1;
  Course c2("CompSci317","401");
  DaysOfTheWeek d("MWF");
  DigitalTime dt1(9,30);
  DigitalTime dt2(10,45);
  TimeInterval t(dt1,dt2);
  Course c3("CompSci337","401",d, t, "Rock");

  cout << "Course name: " << c1.getCourseName() << endl;
  cout << "Section: " << c1.getSection() << endl;
  cout << "Days met: " << c1.getDaysMet() << endl;
  cout << "Time met: " << c1.getTime() << endl;
  cout << "Instructor: " << c1.getInstructor() << endl;
  cout << endl;

  cout << "Course name: " << c2.getCourseName() << endl;
  cout << "Section: " << c2.getSection() << endl;
  cout << "Days met: " << c2.getDaysMet() << endl;
  cout << "Time met: " << c2.getTime() << endl;
  cout << "Instructor: " << c2.getInstructor() << endl;
  cout << endl;

  cout << "Course name: " << c3.getCourseName() << endl;
  cout << "Section: " << c3.getSection() << endl;
  cout << "Days met: " << c3.getDaysMet() << endl;
  cout << "Time met: " << c3.getTime() << endl;
  cout << "Instructor: " << c3.getInstructor() << endl;
  cout << endl;

  c1.setCourseName("CompSci417");
  c1.setSection("001");
  c1.setDaysMet("MW");
  c1.setTime(dt1, dt2);
  c1.setInstructor("Suzuki");

  cout << "Course name: " << c1.getCourseName() << endl;
  cout << "Section: " << c1.getSection() << endl;
  cout << "Days met: " << c1.getDaysMet() << endl;
  cout << "Time met: " << c1.getTime() << endl;
  cout << "Instructor: " << c1.getInstructor() << endl;
  cout << endl;

  c2.setInstructor("Suzuki");
  c2.setTime(dt1, dt2);
  cout << "Does c1 overlap with c2?" << endl;
  if(c1 && c2) {
    cout << "true" << endl;
  }

  Course c4("CompSci417","001");
  cout << "Does c1 match c4?" << endl;
  if (c1 == c4) {
    cout << "true" << endl;
  }

  cout << c3 << endl;

  return 0;
}
*/
