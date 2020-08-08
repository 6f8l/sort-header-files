// 10th lecture task.

// Randomly include standard and custom libraries
#include <sstream>
#include <fstream>
#include <vector>
#include <sstream>

// Custom header file
#include "myclass.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
protected:
  string id;
  string name;

public:
  void setName(const string &newName) { name = newName; }
  string getName() { return name; }
  void setID(string newID) { id = newID; }
  string getID() { return id; }
};

class TMU_Student : public Student {
  string department;

public:
  void setDepartment(string newDepartment) { department = newDepartment; }
  string getDepartment() { return department; }
};

vector<string> split(string &input, char delimiter) {
  istringstream stream(input);
  string field;
  vector<string> result;
  while (getline(stream, field, delimiter)) {
    result.push_back(field);
  }
  return result;
}

int main() {
  ifstream ifs("students.csv");

  string line;
  vector<TMU_Student> people;

  while (getline(ifs, line)) {
    TMU_Student person;
    vector<string> strvec = split(line, ',');

    for (int i = 0; i < strvec.size(); i++) {
      if (i % 3 == 0) {
        person.setID(strvec[i]);
      } else if (i % 3 == 1) {
        person.setName(strvec[i]);
      } else if (i % 3 == 2) {
        person.setDepartment(strvec[i]);

        if (person.getName() != "name" || person.getID() != "id") {
          people.emplace_back(person);
        }
      }
    }
  }

  // 出力
  for (int i = 0; i < people.size(); i++) {
    cout << "id: " << people[i].getID() << ", name: " << people[i].getName()
         << ", department: " << people[i].getDepartment() << endl;
  }
}
