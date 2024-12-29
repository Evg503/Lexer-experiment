#include "EndOfFileComponent.h"
#include <stdexcept>

EndOfFileComponent::EndOfFileComponent(InputStream& input) : source(input) {}

bool EndOfFileComponent::tryTokenize() {
    return source.isAtEnd();
}

Token EndOfFileComponent::nextToken() {
    if (tryTokenize()) {
        return {TokenType::EndOfFile, ""};
    }
    throw std::runtime_error(std::string(__PRETTY_FUNCTION__) + " : Unexpected character");
}

bool EndOfFileComponent::hasMoreTokens() const {
    return !source.isAtEnd();
}