#include "KeywordComponent.h"

KeywordComponent::KeywordComponent(InputStream &input, const std::unordered_set<std::string_view> &keywords)
    : KnownTokenComponent<IdentifierComponent>(input)
{
    for (const auto &keyword : keywords)
    {
        knownTokens[keyword] = TokenType::Keyword;
    }
}
