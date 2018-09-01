#include "main.h"

int size;

bool validateSchedule(Course schedule[]) {
  if (size == 0) return false;
  string instructors[size];
  int instSize = 0;
  int overlap = false;
  for (int i = 0; i < size - 1; i++) {
    bool isMatch = false;
    if (instSize != 0) {
      for (int j = 0; j < instSize; j++) {
        if (schedule[i].getInstructor().compare(instructors[j]) == 0) {
          isMatch = true;
          break;
        }
      }
    }
    if (!isMatch) {
      instSize++;
      for (int j = i + 1; j < size; j++) {
        if (schedule[i].getInstructor().compare(schedule[j].getInstructor()) == 0) {
          if ((schedule[i].getDaysMet() && schedule[j].getDaysMet()) && (schedule[i].getTime() && schedule[j].getTime())) {
            cout << "Alert! " << schedule[i].getCourseName() << " overlaps with " << schedule[j].getCourseName() << endl;
            overlap = true;
          }
        }
      }
    }
  }
  return overlap;
}

string addCourse(Course schedule[], DaysOfTheWeek& days, DigitalTime& start, DigitalTime& end, string name, string section, string instructor) {
  DigitalTime zero(0,0);
  TimeInterval time(start, end);
  if(days.getDays().compare("O") == 0) {
    if ((start != zero) || (end != zero)) {
      return "online class " + name + " should have no set times";
    }
  }
  else {
    if ((time.getStart() == zero) && (time.getEnd() == zero)) {
      return "course " + name + " needs to have a meet time";
    }
  }

  if (section.length() != 3) {
    return "section " + section + " of invalid format";
  }

  if (size == 30) {
    cout << "You've already scheduled THIRTY classes. Don't you think that's enough?"  << endl;
  }

  if (size != 0) {
    for (int i = 0; i < size; i++) {
      if (schedule[i].getCourseName().compare(name) == 0) {
        if (schedule[i].getSection().compare(section) == 0) {
          return "same course name and section detected in existing schedule!";
        }
      }
    }
  }
  Course c(name, section, days, time, instructor);
  schedule[size] = c;
  size++;
  return "OK";
}

bool exportSchedule(Course schedule[], string filename) {
  ofstream output(filename.c_str());
  if (!output.is_open()) {
    cout << "Error: could not open file " << filename << endl;
    return false;
  }
  for (int i = 0; i < size; i++) {
    output << schedule[i].getDaysMet() << " ";
    output << schedule[i].getTime().getStart() << " ";
    output << schedule[i].getTime().getEnd() << " ";
    output << schedule[i].getCourseName() << " ";
    output << schedule[i].getSection() << " ";
    output << schedule[i].getInstructor() << "\n";
  }
  output.close();
  return true;
}

bool importSchedule(Course schedule[], string filename) {
  ifstream input(filename.c_str());
  if (!input.is_open()) {
    cout << "Error: could not open file " << filename << endl;
    return false;
  }
  string line;
  stringstream ss;
  int lineNumber = 1;
  while (getline(input, line)) {
    ss.clear();
    ss.str("");
    ss << line;
    DaysOfTheWeek days;
    DigitalTime start;
    DigitalTime end;
    string courseName;
    string section;
    string instructor;
    ss >> days >> start >> end >> courseName >> section >> instructor;
    string message = addCourse(schedule, days, start, end, courseName, section, instructor);
    if (message.compare("OK") != 0) {
      cout << "Error on line " << lineNumber << ": ";
      cout << line << endl;
      cout << message << endl;
    }
    lineNumber++;
  }
  input.close();
  return true;
}


int main() {
  Course schedule[30];
  size = 0;
  string commands[] = {"quit","clear","remove","validate","add","export","import"};
  string input;

  for (int i = 0; i < 30; i++) {
    Course c;
    schedule[i] = c;
  }

  while (true) {
    cout << "What would you like to do?" << endl;
    cin >> input;

    if (input.compare(commands[0]) == 0) {
      cout << "Goodbye!" << endl;
      break;
    }
    else if (input.compare(commands[1]) == 0) {
      for (int i = 0; i < size; i++) {
        Course c;
        schedule[i] = c;
      }
      size = 0;
      cout << "Schedule cleared!" << endl;
    }
    else if (input.compare(commands[2]) == 0) {
      if (size == 0) {
        cout << "Schedule is empty - cannot remove course" << endl;
      }
      else {
        string courseName;
        string section;
        cin >> courseName >> section;
        int index = 30;
        for (int i = 0; i < size; i++) {
          if ((schedule[i].getCourseName().compare(courseName) == 0) && (schedule[i].getSection().compare(section) == 0)) {
            index = i;
            break;
          }
        }
        if (index == 30) {
          cout << "Cannot remove course - no matching courses in existing schedule" << endl;
        }
        else {
          Course c;
          schedule[index] = c;
          size--;
          for (int i = index; i < size; i++) {
            schedule[i] = schedule[i+1];
          }
          cout << courseName << " successfully removed from schedule!" << endl;
        }
      }
    }
    else if (input.compare(commands[3]) == 0) {
      if (!validateSchedule(schedule)) {
        cout << "Schedule is valid!" << endl;
      }
    }
    else if (input.compare(commands[4]) == 0) {
      DaysOfTheWeek days;
      DigitalTime start;
      DigitalTime end;
      string courseName;
      string section;
      string instructor;
      cin >> days >> start >> end >> courseName >> section >> instructor;
      string message = addCourse(schedule, days, start, end, courseName, section, instructor);
      if (message.compare("OK") == 0) {
         cout << courseName << " added to schedule!" << endl;
      }
      else {
        cout << "Could not add course: " << message << endl;
      }
    }
    else if (input.compare(commands[5]) == 0) {
      string filename;
      cin >> filename;
      if (exportSchedule(schedule,filename)) {
        cout << "Schedule successfully exported to file " << filename << "!" << endl;
      }
    }
    else if (input.compare(commands[6]) == 0) {
      string filename;
      cin >> filename;
      if (importSchedule(schedule,filename)) {
        cout << "Schedule successfully imported from file " << filename << "!" << endl;
      }
    }
    else {
      cout << "Error: cannot recognize command" << endl;
    }

    cout << endl;

/*    cout << "Current schedule:" << endl;
    for (int i = 0; i < size; i++) {
      cout << schedule[i] << endl;
    }
    cout << endl;
*/
  }
  return 0;
}
