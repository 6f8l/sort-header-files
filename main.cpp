#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Header_File_Line {
protected:
  string line;

public:
  void setLine(const string &newLine) { line = newLine; }
  string getLine() { return line; }
};

class File {
protected:
  string name;

public:
  void setName(const string &newName) { name = newName; }
  string getName() { return name; }

  // outputSortedFiles creates "output.txt" that contains sorted header files.
  void outputSortedFiles() {
    vector<Header_File_Line> hf_lines;
    ofstream outfile("output.txt", ios_base::out);

    hf_lines = getSortedHeaderFiles();

    for (vector<Header_File_Line>::iterator itr = hf_lines.begin();
         itr != hf_lines.end(); ++itr) {
      outfile << itr->getLine() << "\n";
    }

    outfile.close();
    cout << "Sorted header files are shown in \"output.txt\"" << endl;
  }

  // sortHeaderFiles sorts the vector elements by rules.
  vector<Header_File_Line> sortHeaderFiles(vector<Header_File_Line> lines) {
    // TODO
    return lines;
  }

  // getSortedHeaderFiles returns vector that contains sorted header files.
  vector<Header_File_Line> getSortedHeaderFiles() {
    vector<Header_File_Line> hf_lines;
    string line;
    ifstream datafile(name);

    while (getline(datafile, line)) {
      Header_File_Line hf_line;

      // Add header files that contain "#include" in the line to header_files
      if (!line.find("#include")) {
        hf_line.setLine(line);
        hf_lines.push_back(hf_line);
      }
    }

    // Execute sort.
    hf_lines = sortHeaderFiles(hf_lines);

    return hf_lines;
  }
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

  file.outputSortedFiles();
  return 0;
}
