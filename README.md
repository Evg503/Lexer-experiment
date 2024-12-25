# Lexer

A simple lexer implementation in C++ that tokenizes identifiers, numbers, operators, quoted strings, and comments.

## Building the Project

1. Clone the repository:
    ```sh
    git clone <repository-url>
    cd Lexer
    ```

2. Create a build directory and navigate to it:
    ```sh
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:
    ```sh
    cmake ..
    ```

4. Build the project:
    ```sh
    make
    ```

## Running the Tests

1. After building the project, run the tests:
    ```sh
    ./LexerTest
    ```

## Usage

You can use the `Lexer` class to tokenize a given source string. Here is an example:

```cpp
#include "Lexer.h"
#include <iostream>

int main() {
    Lexer lexer("abc 123 + \"hello\" // comment");
    while (lexer.hasMoreTokens()) {
        auto token = lexer.nextToken();
        std::cout << token.to_string() << std::endl;
    }
    return 0;
}
```
