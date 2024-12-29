#include "SpaceComponent.h"


Token SpaceComponent::nextToken() {
    if (isSpace()) {
        source.BeginTransaction();
        while (!source.isAtEnd() && isSpace()) {
            source.advance();
        }
        auto space = source.getSubstring();
        source.Commit();
        return {TokenType::Whitespace, space};
    }
    throw std::runtime_error(std::string(__PRETTY_FUNCTION__) + " : Unexpected character");
}

