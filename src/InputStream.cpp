#include "InputStream.h"

InputStream::InputStream(std::string_view source) : source(source), position(0)
{
}

InputStream::~InputStream()
{
}

