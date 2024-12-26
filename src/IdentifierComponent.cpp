#include "IdentifierComponent.h"
#include <cctype>
#include <stdexcept>

IdentifierComponent::IdentifierComponent(InputStream& source) : source(source) {}

bool IdentifierComponent::tryTokenize()
{
    return isAlpha(source.currentChar());
}

Token IdentifierComponent::nextToken() {

    if (source.isAtEnd()) {
        throw std::runtime_error(std::string(__PRETTY_FUNCTION__) +  " : Unexpected end of file");
    }

    if (isAlpha(source.currentChar())) {
        source.BeginTransaction();
        while (!source.isAtEnd() && isAlpha(source.currentChar())) {
            source.advance();
        }
        auto text = source.getSubstring();
        source.Commit();
        return {TokenType::Identifier, text};
    }

    throw std::runtime_error(std::string(__PRETTY_FUNCTION__) +  " : Unexpected character");
}

bool IdentifierComponent::hasMoreTokens() const
{
    return false;
}

bool IdentifierComponent::isAlpha(char c) const {
    return std::isalpha(static_cast<unsigned char>(c));
}
