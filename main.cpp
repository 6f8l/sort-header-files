#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string OUTPUT_FILE_NAME = "output.txt";

class Header_File_Line {
private:
  string line;

public:
  void setLine(const string &newLine) { line = newLine; }
  string getLine() { return line; }
};

bool sortByAlphabet(Header_File_Line &A, Header_File_Line &B) {
  return (A.getLine() < B.getLine());
}

class File {
private:
  string name;

public:
  void setName(const string &newName) { name = newName; }
  string getName() { return name; }

  // outputSortedFiles creates "output.txt" that contains sorted header files.
  void outputSortedFiles() {
    vector<Header_File_Line> hf_lines;
    ofstream outfile(OUTPUT_FILE_NAME, ios_base::out);

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
    vector<Header_File_Line> standard_lines;
    vector<Header_File_Line> custom_lines;
    vector<Header_File_Line> sorted_lines;

    // Split lines into standard library lines & custom library lines.
    for (int i = 0; i < lines.size(); i++) {
      if (lines[i].getLine().find("#include \"") != 1) {
        custom_lines.push_back(lines[i]);
      } else if (lines[i].getLine().find("#include <") != 1) {
        standard_lines.push_back(lines[i]);
      } else {
        cout << "ERROR: The target file contains an unacceptable header file"
             << endl;
      }
    }

    // Execute sort and add custom library lines to vector
    sort(custom_lines.begin(), custom_lines.end(), sortByAlphabet);
    for (int i = 0; i < custom_lines.size(); i++) {
      sorted_lines.push_back(custom_lines[i]);
    }

    // Execute sort and add standard library lines to vector
    sort(standard_lines.begin(), standard_lines.end(), sortByAlphabet);
    for (int i = 0; i < standard_lines.size(); i++) {
      sorted_lines.push_back(standard_lines[i]);
    }

    return sorted_lines;
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
