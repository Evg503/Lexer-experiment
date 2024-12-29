#pragma once

#include "Component.h"
#include "Token.h"
#include "InputStream.h"

class DigitComponent : public Component {
public:
    DigitComponent(InputStream& source);
    
    bool tryTokenize() override;
    Token nextToken() override;
    bool hasMoreTokens() const override;

private:
    InputStream& source;
    bool isDigit(char c) const;
};
