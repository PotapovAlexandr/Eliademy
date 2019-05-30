#include "StringKeeper.h"



StringKeeper::StringKeeper(const std::string &str)
{
    bufer = std::make_shared<std::string>(str);
}

StringKeeper::StringKeeper(const StringKeeper &other)
{
    bufer = other.bufer;
}

StringKeeper& StringKeeper::operator=(const StringKeeper &other)
{
    StringKeeper temp(other);
    Swap(temp);
    return *this;
}

const std::string& StringKeeper::Get() const
{
    return *bufer.get();
}

std::string& StringKeeper::Get()
{
    bufer.reset(new std::string(*bufer.get()));
    return *bufer.get();
}
