#include "QuotedStringComponent.h"

QuotedStringComponent::QuotedStringComponent(InputStream &source) : source(source)
{
}

bool QuotedStringComponent::tryTokenize()
{
    if (isQuote(source.currentChar()))
    {
        return true;
    }
    return false;
}

Token QuotedStringComponent::nextToken()
{
    auto quotedString = extractQuotedString();
    return {TokenType::QuotedString, quotedString};
}

bool QuotedStringComponent::isQuote(char c)
{
    return c == '"' || c == '\'' || c == '`';
}

std::string_view QuotedStringComponent::extractQuotedString()
{
    char quoteChar = source.currentChar();
    source.advance(); // Skip the opening quote
    source.BeginTransaction();

    while (!source.isAtEnd() && source.currentChar() != quoteChar)
    {
        source.advance();
    }
    auto result = source.getSubstring();
    
    if (!source.isAtEnd())
    {
        source.advance(); // Skip the closing quote
    }
    source.Commit();

    return result;
}