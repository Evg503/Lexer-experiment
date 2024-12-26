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

class Lexer : public Component
{
public:

    bool hasMoreTokens() const override;
    std::vector<Token> getNextLineTokens();
    Lexer(std::string_view source);

    bool tryTokenize() override;

    Token nextToken() override;

    void skipWhitespace();
    Token extractQuotedString();

private:
    InputStream source;
    IdentifierComponent identifierComponent;
    DigitComponent digitComponent;
    OperatorComponent operatorComponent;
    QuotedStringComponent quotedStringComponent; // New component for quoted strings
    CommentStringComponent commentStringComponent; // New component for comments

};
