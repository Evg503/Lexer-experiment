#pragma once

#include "Component.h"
#include "Token.h"
#include "InputStream.h"

class IdentifierComponent : public Component {
public:
    IdentifierComponent(InputStream& source);

    bool tryTokenize() override;

    Token nextToken() override;
    bool hasMoreTokens() const override;


private:
    InputStream& source;
    bool isAlpha(char c) const;
};
