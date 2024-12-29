#pragma once
#include "Token.h"


class Component {
public:
    Component() = default;
    virtual ~Component() = default;
    virtual bool tryTokenize() = 0;
    virtual Token nextToken() = 0;
    virtual bool hasMoreTokens() const { return false; };


};
