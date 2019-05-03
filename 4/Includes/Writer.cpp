#include "Writer.h"
#include "Content.h"
#include <sstream>
#include <fstream>

void Writer::Write(std::stringstream& strm)
{
    strm << "B::Write(std::stringstream& strm)\n";
}

void Writer::Write(std::fstream& strm)
{
    strm << "B::Write(std::fstream& strm)\n";
}

void Writer::WriteFrom(const Content& c, std::string& dest)
{
    dest = c.Read();
}
