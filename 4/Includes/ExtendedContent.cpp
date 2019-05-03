#include "ExtendedContent.h"
#include "Writer.h"

ExtendedContent::ExtendedContent(const std::string& text)
    : Content(text.c_str())
{ }

ExtendedContent ExtendedContent::CreateFrom(Content* a) const
{
    return ExtendedContent(a->Read());
}

std::string ExtendedContent::WriteWith(Writer* b) const
{
    std::string text;
    b->WriteFrom(*this, text);
    return text;
}
