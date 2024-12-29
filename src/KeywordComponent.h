#ifndef KEYWORDCOMPONENT_H
#define KEYWORDCOMPONENT_H

#include "Component.h"
#include "IdentifierComponent.h"
#include "Token.h"
#include <unordered_set>

class KeywordComponent : public Component
{
public:
    KeywordComponent(InputStream &input, const std::unordered_set<std::string_view> &keywords);

    bool tryTokenize() override;
    Token nextToken() override;
    bool hasMoreTokens() const override;

private:
    IdentifierComponent identifierComponent;
    std::unordered_set<std::string_view> keywords;
};

#endif // KEYWORDCOMPONENT_H