
#pragma once
#include <string_view>
#include <vector>
#include <string>

enum class TokenType
{
    Identifier,
    Number,
    Operator,
    QuotedString,
    Comment,
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
        case TokenType::Comment:
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
