#pragma once

#include "Component.h"
#include "Token.h"
#include <unordered_map>
#include <memory>

template <typename C>
concept ComponentType = requires(C c)
{
    { c.tryTokenize() }
    ->std::same_as<bool>;
    { c.nextToken() }
    ->std::same_as<Token>;
    { c.hasMoreTokens() }
    ->std::same_as<bool>;
};

template <ComponentType C>
class KnownTokenComponent : public Component
{
public:
    KnownTokenComponent(InputStream &input, std::unordered_map<std::string_view, TokenType> knownTokens = {})
        : source(input), knownTokens(std::move(knownTokens)), decoratedComponent(input) {}

    bool tryTokenize() override
    {
        return decoratedComponent.tryTokenize();
    }
    Token nextToken() override
    {
        Token token = decoratedComponent.nextToken();
        auto it = knownTokens.find(token.text);
        if (it != knownTokens.end())
        {
            token.type = it->second;
        }
        return token;
    }
    bool hasMoreTokens() const override
    {
        return decoratedComponent.hasMoreTokens();
    }

protected:
    InputStream &source;
    std::unordered_map<std::string_view, TokenType> knownTokens;
    C decoratedComponent;
};
