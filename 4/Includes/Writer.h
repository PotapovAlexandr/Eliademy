#pragma once
#include <iosfwd>
#include <string>

class Content;
class Writer
{
public:
    void Write(std::stringstream& strm);
    void Write(std::fstream& strm);
    void WriteFrom(const Content& c, std::string& dest);
};

