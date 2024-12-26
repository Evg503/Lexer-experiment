#include "CommentStringComponent.h"

Token CommentStringComponent::nextToken()
{
    source.advance(); // Skip the first '/'
    source.advance(); // Skip the second '/'
    source.BeginTransaction();
    while (!source.isAtEnd() && source.currentChar() != '\n')
    {
        source.advance();
    }
    auto text = source.getSubstring();
    source.Commit();
    return {TokenType::Comment, text};
}

bool CommentStringComponent::tryTokenize()
{
    // if (source.currentChar() == '#')
    // {
    //     return true;
    // }
    if (source.currentChar() == '/')
    {
        source.BeginTransaction();
        source.advance();
        if (source.currentChar() == '/')
        {
            source.Rollback();
            return true;
        }
        source.Rollback();
    }
    return false;
}

bool CommentStringComponent::hasMoreTokens() const
{
    return false;
}
