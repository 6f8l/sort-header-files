#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class File {
protected:
  string name;

public:
  void setName(const string &newName) { name = newName; }
  string getName() { return name; }
  void outputResult() {}
};

class Header_File {
protected:
  string name;

public:
  void setName(const string &newName) { name = newName; }
  string getName() { return name; }
};

int main(int argc, char *argv[]) {
  int i;
  File file;

  // Validate CLI arguments and substitute the file name.
  if (argc != 2) {
    cout << "FAILED: You need to specify one file that you want to "
            "rearrange header files."
         << endl;
    return 0;
  } else {
    file.setName(argv[1]);
  }

  cout << file.getName() << endl;
  return 0;
}
