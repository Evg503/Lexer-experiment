#include "OperatorComponent.h"
#include <stdexcept>


OperatorComponent::OperatorComponent(InputStream& source) : source(source) {        
    // Constructor implementation
}

OperatorComponent::~OperatorComponent() {
    // Destructor implementation
}

bool OperatorComponent::isOperator(char c) {
    // Check if the character is an operator
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case '<':
        case '>':
        case '!':
        case '&':
        case '|':
        case '^':
        case '~':
            return true;
        default:
            return false;
    }
}

Token OperatorComponent::nextToken() {
    // Get the next operator token
    if (source.isAtEnd()) {
        throw std::runtime_error("Unexpected end of file");
    }

    if (isOperator(source.currentChar())) {
        source.BeginTransaction();
        while (!source.isAtEnd() && isOperator(source.currentChar())) {
            source.advance();
        }
        auto text = source.getSubstring();
        source.Commit();
        return {TokenType::Operator, text};
    }
    source.Rollback();
    throw std::runtime_error("Unexpected character");
}

bool OperatorComponent::tryTokenize()
{
    return isOperator(source.currentChar());
}
