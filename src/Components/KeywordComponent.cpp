#include "KeywordComponent.h"

KeywordComponent::KeywordComponent(InputStream &input, const std::unordered_set<std::string_view> &keywords)
    : identifierComponent(input), keywords(keywords) {}

bool KeywordComponent::tryTokenize()
{
    return identifierComponent.tryTokenize();
}

Token KeywordComponent::nextToken()
{
    Token token = identifierComponent.nextToken();
    if (keywords.find(token.text) != keywords.end())
    {
        token.type = TokenType::Keyword;
    }
    return token;
}

bool KeywordComponent::hasMoreTokens() const
{
    return identifierComponent.hasMoreTokens();
}