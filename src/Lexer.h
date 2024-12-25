#pragma once

#include <string_view>
#include <vector>
#include <string>

class Lexer
{
public:
    enum class TokenType
    {
        Identifier,
        Number,
        Operator,
        QuotedString,
        Comment, // Added new token type
        EndOfFile,
        Unknown
    };

    struct Token
    {
        TokenType type;
        std::string_view text;
        std::string to_string() const
        {
            switch (type)
            {
            case TokenType::Identifier:
                return "Identifier: [" + std::string(text) + "]";
            case TokenType::Number:
                return "Number: [" + std::string(text) + "]";
            case TokenType::Operator:
                return "Operator: [" + std::string(text) + "]";
            case TokenType::QuotedString:
                return "QuotedString: [" + std::string(text) + "]";
            case TokenType::Comment: // Added case for comment
                return "Comment: [" + std::string(text) + "]";
            case TokenType::EndOfFile:
                return "EndOfFile";
            case TokenType::Unknown:
                return "Unknown: [" + std::string(text) + "]";
            default:
                return "Invalid Token";
            }
        }
    };
    bool hasMoreTokens() const;
    std::vector<Token> getNextLineTokens();
    Lexer(std::string_view source);

    Token nextToken();

private:
    std::string_view source;
    size_t position;

    char currentChar() const;
    void advance();
    bool isAlpha(char c) const;
    bool isDigit(char c) const;
    bool isOperatorStart() const; // Updated method declaration
    bool isQuote(char c) const;
    bool isCommentStart() const; // Added method declaration
};
