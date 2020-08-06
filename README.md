# Sort header files
This program rearranges the `#include ~` header files that appear in the middle of a program written in C++.

## Installation
```
git clone https://github.com/othneildrew/Best-README-Template
```

## Usage
Build the `main.cpp` by specifying the target file as an argument and execute the binary.

When you run the program, the header files you created will be sorted in the order of the standard library.

In other words, it is a mechanism that sort is executed in the order of `#include "~"`, `#include <~>`.

The example command is presented below.
```
cd /path/to/this/repository
g++ main.cpp <TARGET_FILE> -o main && ./main
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
