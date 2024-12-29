#include "Lexer.h"
#include <cctype>
#include "SpaceComponent.h"
#include "EndOfFileComponent.h"
#include "KeywordComponent.h"
#include "UnknownComponent.h"

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
    std::unordered_set<std::string_view> keywords = {"if", "else", "while", "return"};

    components.push_back(std::make_unique<EndOfFileComponent>(source));
    components.push_back(std::make_unique<CommentStringComponent>(source));
    components.push_back(std::make_unique<DigitComponent>(source));
    components.push_back(std::make_unique<OperatorComponent>(source));
    components.push_back(std::make_unique<KeywordComponent>(source, keywords));
    components.push_back(std::make_unique<QuotedStringComponent>(source));
    components.push_back(std::make_unique<SpaceComponent>(source));
    components.push_back(std::make_unique<UnknownComponent>(source));

    // Define keywords
}

bool Lexer::tryTokenize()
{
    return true;
}

Token Lexer::nextToken()
{
    for (auto& component : components)
    {
        if (component->tryTokenize())
        {
            return component->nextToken();
        }
    }

    throw std::runtime_error("No matching component found");
}
