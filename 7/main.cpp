#include <QCoreApplication>
#include <iostream>

#include "StringKeeper.h"

void Print(StringKeeper sk)
{
    sk.Get() = "temp";
    std::cout << sk.Get() << "\n";
}

int main(int argc, char *argv[])
{
    StringKeeper str("One");
    StringKeeper str2 = str;
    StringKeeper str3("Three");
    str2 = str3;
    str2.Get() = "Two";
    std::cout << str.Get() << "\n"
              << str2.Get() << "\n";
    std::string st;
    st = str.Get();
    std::cout << str.Get() << "\n"
              << st << "\n";
    st = "string";
    std::cout << str.Get() << "\n"
              << st << "\n";

    Print(str2);
    return 0;
}
