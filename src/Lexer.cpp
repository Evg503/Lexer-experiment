#include "Lexer.h"
#include <cctype>

bool Lexer::hasMoreTokens() const
{
    return !source.isAtEnd();
}

std::vector<Token> Lexer::getNextLineTokens()
{
    std::vector<Token> tokens;
    while (hasMoreTokens())
    {
        tokens.push_back(nextToken());
    }
    return tokens;
}

Lexer::Lexer(std::string_view source)
    : source(source)
    , identifierComponent(this->source)
    , digitComponent(this->source)
    , operatorComponent(this->source) 
    , quotedStringComponent(this->source)
    , commentStringComponent(this->source) // Initialize CommentStringComponent
    {}

    bool Lexer::tryTokenize()
    {
        return true;
    }

void Lexer::skipWhitespace()
{
    source.skipWhitespace();
}

Token Lexer::nextToken()
{
    skipWhitespace();

    if (source.isAtEnd())
    {
        return {TokenType::EndOfFile, ""};
    }

    if (commentStringComponent.tryTokenize())
    {
        return commentStringComponent.nextToken();
    }
    if (identifierComponent.tryTokenize())
    {
        return identifierComponent.nextToken();
    }

    if (digitComponent.tryTokenize())
    {
        return digitComponent.nextToken();
    }

    if (operatorComponent.tryTokenize())
    {
        return operatorComponent.nextToken();
    }

    if (quotedStringComponent.tryTokenize())
    {
        return quotedStringComponent.nextToken();
    }


    source.BeginTransaction();
    source.advance();
    auto text = source.getSubstring();
    source.Commit();
    return {TokenType::Unknown, text};
}
