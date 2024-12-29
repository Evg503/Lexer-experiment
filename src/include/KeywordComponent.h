#pragma once

#include "Component.h"
#include "IdentifierComponent.h"
#include "Token.h"
#include <unordered_map>
#include <unordered_set>
#include "KnownTokenComponent.h"


class KeywordComponent : public KnownTokenComponent<IdentifierComponent>
{
public:
    KeywordComponent(InputStream &input, const std::unordered_set<std::string_view> &keywords);

};  

