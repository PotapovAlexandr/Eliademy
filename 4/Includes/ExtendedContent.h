#pragma once
#include "Content.h"

class Writer;
class ExtendedContent: public Content
{
public:
    ExtendedContent(const std::string& text);
    ExtendedContent CreateFrom(Content* a) const;
    std::string WriteWith(Writer* b) const;
};

