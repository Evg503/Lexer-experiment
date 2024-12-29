#include "UnknownComponent.h"
#include <stdexcept>

UnknownComponent::UnknownComponent(InputStream& input) : source(input) {}

bool UnknownComponent::tryTokenize() {
    return !std::isspace(source.currentChar()) && !source.isAtEnd();
}

Token UnknownComponent::nextToken() {
    if (tryTokenize()) {
        source.BeginTransaction();
        source.advance();
        auto text = source.getSubstring();
        source.Commit();
        return {TokenType::Unknown, text};
    }
    throw std::runtime_error(std::string(__PRETTY_FUNCTION__) + " : Unexpected character");
}

bool UnknownComponent::hasMoreTokens() const {
    return !source.isAtEnd();
}