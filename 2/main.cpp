#include <QCoreApplication>
#include <iostream>
#include <set>
#include <string>

#include "DataKeeper.h"

int main(int argc, char *argv[])
{
    uint8_t data1[] {1, 2, 3, 4, 5};
    DataKeeper keeper;

    keeper.Set(data1, 5);

    const uint8_t* temp = keeper.Get();
    for(int i = 0; i < 5; ++i)
    {
        std::cout << temp;
        ++temp;
    }
    uint8_t data2[] {6, 7, 8, 9, 0};

    keeper.Add(data2, 5);

    const uint8_t* temp2 = keeper.Get();
    for(int i = 0; i < 10; ++i)
    {
        std::cout << temp2;
        ++temp2;
    }


    return 1;
}
