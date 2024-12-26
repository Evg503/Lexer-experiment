
#pragma once
#include <string_view>
#include <cctype>


class InputStream
{
private:
    std::string_view source;
    size_t position;
    size_t start;

public:
    InputStream(std::string_view source);
    ~InputStream();

    char currentChar() const
    {
        return source[position];
    }

    void advance()
    {
        if (position < source.size())
        {
            ++position;
        }
    }
    size_t getPosition() const
    {
        return position;
    }
    void setPosition(size_t pos)
    {
        position = pos;
    }
    std::string_view getSubstring() const
    {
        return source.substr(start, position - start);
    }
    size_t getSize() const
    {
        return source.size();
    }
    void BeginTransaction()
    {
        start = position;
    }
    void Rollback()
    {
        position = start;
    }
    void Commit()
    {
        start = 0;
    }
    bool isAtEnd() const
    {
        return position >= source.size();
    }
    void skipWhitespace()
    {
        while (position < source.size() && std::isspace(currentChar()))
        {
            advance();
        }
    }
};