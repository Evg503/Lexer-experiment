#pragma once

#include "Component.h"
#include "Token.h"
#include "InputStream.h"

class CommentStringComponent : public Component {
public:
    CommentStringComponent(InputStream& source) : source(source) {}
    bool tryTokenize() override;
    Token nextToken() override;
    bool hasMoreTokens() const override;

private:
    InputStream& source;
    
};
