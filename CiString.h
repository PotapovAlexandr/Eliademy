#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <set>

struct CiCharTraits : public std::char_traits<char>
{
    static bool eq(char left, char right)
    {
        return toupper(left) == toupper(right);
    }
    static bool lt(char left, char right)
    {
        return toupper(left) < toupper(right);
    }
    static int compare(const char* left, const char* right, size_t len)
    {
        return memicmp(left, right, len);
    }
};

typedef std::basic_string < char, CiCharTraits> CiString;

class IgnoreCaseSet : public std::set<CiCharTraits>
{
public:
    IgnoreCaseSet();
};
