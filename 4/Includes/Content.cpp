#include "Content.h"

Content::Content(const char* text)
    : m_text(text)
{ }

const char* Content::Read() const
{
    return m_text.c_str();
}

