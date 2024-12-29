#pragma once

#include "Component.h"
#include "InputStream.h"
#include "Token.h"

class UnknownComponent : public Component {
public:
    UnknownComponent(InputStream& input);

    bool tryTokenize() override;
    Token nextToken() override;
    bool hasMoreTokens() const override;

private:
    InputStream& source;
};

