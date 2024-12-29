#include "DigitComponent.h"
#include <cctype>
#include <stdexcept>

DigitComponent::DigitComponent(InputStream& source) : source(source) {}

bool DigitComponent::tryTokenize()
{
    return isDigit(source.currentChar());
}

Token DigitComponent::nextToken()
{

    if (source.isAtEnd()) {
        throw std::runtime_error("Unexpected end of file");
    }

    if (isDigit(source.currentChar())) {
        source.BeginTransaction();
        while (!source.isAtEnd() && isDigit(source.currentChar())) {
            source.advance();
        }
        auto text = source.getSubstring();
        source.Commit();
        return {TokenType::Number, text};
    }

    throw std::runtime_error("Unexpected character");
}

bool DigitComponent::hasMoreTokens() const {
    return !source.isAtEnd();
}

bool DigitComponent::isDigit(char c) const {
    return std::isdigit(static_cast<unsigned char>(c));
}
