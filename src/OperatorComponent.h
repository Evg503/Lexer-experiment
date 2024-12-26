#pragma once

#include <string>
#include "Component.h"
#include "Token.h"
#include "InputStream.h"


class OperatorComponent : public Component
{
public:
    OperatorComponent(InputStream &source);
    ~OperatorComponent();
    Token nextToken() override;
    bool tryTokenize() override;

private:
    InputStream &source;
    bool isOperator(char c);
};
