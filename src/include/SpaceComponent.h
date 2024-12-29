#pragma once

#include "Component.h"
#include "InputStream.h"
#include "Token.h"
#include <stdexcept>

class SpaceComponent : public Component
{
public:
    SpaceComponent(InputStream &input) : source(input) {}

    bool tryTokenize() override
    {
        return isSpace();
    }

    Token nextToken() override;
    bool hasMoreTokens() const override
    {
        return !source.isAtEnd();
    }

private:
    InputStream &source;

    bool isSpace() const
    {
        return std::isspace(source.currentChar());
    }
};
