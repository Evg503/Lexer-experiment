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

Lexer::Lexer(std::string_view source_view)
    : source(source_view){
    components.push_back(std::make_unique<CommentStringComponent>(source));
    components.push_back(std::make_unique<DigitComponent>(source));
    components.push_back(std::make_unique<OperatorComponent>(source));
    components.push_back(std::make_unique<IdentifierComponent>(source));
    components.push_back(std::make_unique<QuotedStringComponent>(source));
}

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

    for (auto& component : components)
    {
        if (component->tryTokenize())
        {
            return component->nextToken();
        }
    }

    source.BeginTransaction();
    source.advance();
    auto text = source.getSubstring();
    source.Commit();
    return {TokenType::Unknown, text};
}
