#include <QCoreApplication>
#include <iostream>
#include <set>
#include <string>

#include "DataKeeper.h"
#include "CiString.h"

class NewSortOrder
{
public:
    bool operator()(const std::string& left, const std::string& right)
    {
        return strcmpi(left.c_str(), right.c_str());
    }
};


int main(int argc, char *argv[])
{
    using namespace std;
    QCoreApplication a(argc, argv);

    set<CiString> setCiStr;
    setCiStr.insert("math");
    setCiStr.insert("Matha");
    setCiStr.insert("aba");
    setCiStr.insert("Abra");
    setCiStr.insert("5dfg");

    set<string> setStr;
    setStr.insert("math");
    setStr.insert("Matha");
    setStr.insert("aba");
    setStr.insert("Abra");
    setStr.insert("5dfg");

    set<string, NewSortOrder> setWithNewOrder;
    setWithNewOrder.insert("math");
    setWithNewOrder.insert("Matha");
    setWithNewOrder.insert("aba");
    setWithNewOrder.insert("Abra");
    setWithNewOrder.insert("5dfg");

    cout << "Set of string:\n";
    for(auto it = setStr.begin(); it != setStr.end(); ++it)
    {
        cout << *it << "\n";
    }

    cout << "\nSet of CiString:\n";
    for(auto it = setCiStr.begin(); it != setCiStr.end(); ++it)
    {
        cout << (*it).c_str() << "\n";
    }

    cout << "\nSet with newOrder:\n";
    for(auto it = setWithNewOrder.begin(); it != setWithNewOrder.end(); ++it)
    {
        cout << *it << "\n";
    }

    return a.exec();
}
