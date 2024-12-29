#pragma once

#include <string_view>
#include <vector>
#include <string>
#include "Token.h"
#include "Component.h"
#include "InputStream.h"
#include "IdentifierComponent.h"
#include "DigitComponent.h"
#include "OperatorComponent.h"
#include "QuotedStringComponent.h"
#include "CommentStringComponent.h"
#include <memory>

class Lexer : public Component
{
public:

    Lexer(std::string_view source);
    bool tryTokenize() override;
    Token nextToken() override;
    bool hasMoreTokens() const override;

    std::vector<Token> getNextLineTokens();
private:
    InputStream source;
    std::vector<std::unique_ptr<Component>> components;
};
