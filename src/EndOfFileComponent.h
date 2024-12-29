#ifndef ENDOFFILECOMPONENT_H
#define ENDOFFILECOMPONENT_H

#include "Component.h"
#include "InputStream.h"
#include "Token.h"

class EndOfFileComponent : public Component {
public:
    EndOfFileComponent(InputStream& input);

    bool tryTokenize() override;
    Token nextToken() override;
    bool hasMoreTokens() const override;

private:
    InputStream& source;
};

#endif // ENDOFFILECOMPONENT_H