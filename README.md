# Sort header files
This program rearranges the `#include ~` header files that appear in the middle of a program written in C++.

## Installation
```
git clone https://github.com/6f8l/sort-header-files
```

## Usage
Build the `main.cpp` by specifying the target file as an argument and execute the binary.

When you run the program, the header files you created will be sorted in the order of the standard library.

In other words, it is a mechanism that sort is executed in the order of `#include "~"`, `#include <~>`.

The example command is presented below.
```
cd /path/to/this/repository
g++ main.cpp <TARGET_FILE> -o main
./main sample.cpp
```

You can get `output.txt` as a result.

### Output example
If you execute this program specifying `sample.cpp` in this repository as an argument that contains below header files,
```cpp
// Randomly include standard and custom libraries
#include <fstream>
#include <sstream>
#include <vector>

// Custom header file
#include "myclass.h"
#include "a.h"

#include <iostream>
#include <string>
```

you can get `output.txt`.
It has header files sorted in order shown below.
```txt
#include "a.h"
#include "myclass.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
```

## Development environment
```
# Clang version
Apple clang version 11.0.3 (clang-1103.0.32.62)

# Compiler version
gcc version 9.3.0 (Homebrew GCC 9.3.0_1)
```

## License
Distributed under the MIT License. See LICENSE for more information.
