#pragma once
#include <string>

class Content
{
public:
    Content(const char* text);
    const char* Read() const;

protected:
    std::string m_text;
};

