#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// TODO: Use an original class
int sort(string filename) { return 0; }

int main(int argc, char *argv[]) {
  int i;
  string filename;

  // Validate CLI arguments and substitute the filename.
  if (argc != 2) {
    cout << "FAILED: You need to specify one filename that you want to "
            "rearrange header files."
         << endl;
    return 0;
  } else {
    filename = argv[1];
  }

  cout << filename << endl;
  return 0;
}
