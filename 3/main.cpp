#include <QCoreApplication>
#include "Build.h"


int main(int argc, char *argv[])
{
    Building home("Pupkin str, 1", 4, BuildingType::House);
    Building office("Pupkin str, 2", 4, BuildingType::Office);

    HumanGuard bob = std::make_shared<Man>(QDate(1, 1, 2000), "Bob");
    HumanGuard alice = std::make_shared<Woman>(QDate(1, 1, 1990), "Alice");

    Humans_vt familyFromFirstRoom;
    familyFromFirstRoom.push_back(bob);
    familyFromFirstRoom.push_back(alice);
    home.PopulateInAppartment(familyFromFirstRoom, 1);

    Humans_vt EmployeesFromFirstOffice;
    EmployeesFromFirstOffice.emplace_back(bob);
    office.PopulateInAppartment(EmployeesFromFirstOffice, 1);

    Humans_vt EmployeesFromSecondOffice;
    EmployeesFromSecondOffice.emplace_back(alice);
    office.PopulateInAppartment(EmployeesFromSecondOffice, 2);

    home.About();

    office.About();

    return 1;
}
