#pragma once
#include <iostream>
#include <memory>
#include <string>

class StringKeeper
{
public:
    StringKeeper(const std::string& str);
    ~StringKeeper(){}

    StringKeeper(const StringKeeper& other);

    StringKeeper &operator=(const StringKeeper& other);

    const std::string& Get() const;

    std::string& Get();
private:

    void Swap(StringKeeper& other)
    {
        std::swap(bufer, other.bufer);
    }
private:
    std::shared_ptr<std::string> bufer;

};

