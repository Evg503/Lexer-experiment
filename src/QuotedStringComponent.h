
#pragma once

#include "Token.h"
#include "InputStream.h"
#include "Component.h"

class QuotedStringComponent : public Component
{
public:
    QuotedStringComponent(InputStream& source);
    
    bool tryTokenize() override;
    Token nextToken() override;

private:
    InputStream& source;
    std::string_view extractQuotedString();
    bool isQuote(char c);
};