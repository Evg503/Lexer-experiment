#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Lexer.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    try {
        std::ifstream file(argv[1]);
        if (!file) {
            throw std::runtime_error("Could not open file");
        }
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        Lexer lexer(content);
        while (lexer.hasMoreTokens()) {
            std::vector<Token> tokens = lexer.getNextLineTokens();
            for (const Token& token : tokens) {
                std::cout << token.to_string() << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}