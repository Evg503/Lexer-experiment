#include "Lexer.h"
#include <cctype>

// ...existing code...

bool Lexer::hasMoreTokens() const
{
    if (position < source.size())
    {
        return true;
    }
    return false;
}

std::vector<Lexer::Token> Lexer::getNextLineTokens()
{
    if (hasMoreTokens())
    {
        std::vector<Token> tokens;
        while (hasMoreTokens())
        {
            tokens.push_back(nextToken());
        }
        return tokens;
    }
    return std::vector<Token>();
}

Lexer::Lexer(std::string_view source) : source(source), position(0) {}

Lexer::Token Lexer::nextToken()
{
    // Skip whitespace
    while (position < source.size() && std::isspace(currentChar()))
    {
        advance();
    }

    if (position >= source.size())
    {
        return {TokenType::EndOfFile, ""};
    }

    if (isAlpha(currentChar()))
    {
        size_t start = position;
        while (position < source.size() && isAlpha(currentChar()))
        {
            advance();
        }
        return {TokenType::Identifier, source.substr(start, position - start)};
    }

    if (isDigit(currentChar()))
    {
        size_t start = position;
        while (position < source.size() && isDigit(currentChar()))
        {
            advance();
        }
        return {TokenType::Number, source.substr(start, position - start)};
    }

    if (isOperatorStart())
    {
        size_t start = position;
        advance();
        while (isOperatorStart())
        {
            advance();
        }
        return {TokenType::Operator, source.substr(start, position - start)};
    }

    if (isQuote(currentChar()))
    {
        advance(); // Skip the opening quote
        size_t start = position;
        while (position < source.size() && !isQuote(currentChar()))
        {
            advance();
        }
        size_t end = position;
        advance(); // Skip the closing quote
        return {TokenType::QuotedString, source.substr(start, end - start)};
    }

    if (isCommentStart())
    {
        advance(); // Skip the first '/'
        advance(); // Skip the second '/'
        size_t start = position;
        while (position < source.size() && currentChar() != '\n')
        {
            advance();
        }
        return {TokenType::Comment, source.substr(start, position - start)};
    }

    size_t start = position;
    advance();
    return {TokenType::Unknown, source.substr(start, position - start)};
}

char Lexer::currentChar() const
{
    return source[position];
}

void Lexer::advance()
{
    if (position < source.size())
    {
        ++position;
    }
}

bool Lexer::isAlpha(char c) const
{
    return std::isalpha(static_cast<unsigned char>(c));
}

bool Lexer::isDigit(char c) const
{
    return std::isdigit(static_cast<unsigned char>(c));
}

bool Lexer::isQuote(char c) const
{
    return c == '"';
}

bool Lexer::isCommentStart() const
{
    return currentChar() == '/' && position + 1 < source.size() && source[position + 1] == '/';
}

bool Lexer::isOperatorStart() const
{
    if(isCommentStart())
    {
        return false;
    }
    char c = currentChar();
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>' || c == '!' || c == '&' || c == '|' || c == '^' || c == '%' || c == '~';
}
