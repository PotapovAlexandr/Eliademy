#pragma once
#include "Build.h"


Human::Human(const QDate& bdata, const std::string& name):
    m_birthdayDate(bdata),
    m_name(name)
{}

QDate Human::GetBithday()
{
    return m_birthdayDate;
}

void Human::AboutMe()
{
    std::cout << "Name" << m_name << "\n"
              << "Birthday " << m_birthdayDate.toString("dd.MM.yyyy").toStdString() << "\n";
}

Man::Man(const QDate& bdata, const std::string& name):Human(bdata, name){}

void Man::AboutMe()
{
    std::cout << "Man";
    Human::AboutMe();
}

Woman::Woman(const QDate& bdata, const std::string& name):Human(bdata, name){}

void Woman::AboutMe()
{
    std::cout << "Woman";
    Human::AboutMe();
}

Apartment::Apartment(){}

Apartment::Apartment(const Humans_vt& tenants)
{
    m_tenants.reserve(tenants.size());
    m_tenants.insert(m_tenants.begin(), tenants.begin(), tenants.end());
}

void Apartment::Populate(const Humans_vt& newTenants)
{
    m_tenants.clear();
    m_tenants.reserve(newTenants.size());
    m_tenants.insert(m_tenants.begin(), newTenants.begin(), newTenants.end());
}

void Apartment::About()
{
    if (m_tenants.empty())
    {
        std::cout << "No roomers are here.\n";
    }
    for(HumanGuard tenant : m_tenants)
    {
        tenant->AboutMe();
    }
}

Building::Building(const std::string& adress, size_t countOfApartments, BuildingType type):
    m_adress(adress),
    m_countOfApartments(countOfApartments),
    m_type(type)
{
    m_apartments.resize(countOfApartments);

}

void Building::PopulateInAppartment(const Humans_vt& people, size_t roomNumber)
{
    if (roomNumber > m_countOfApartments)
    {
        return;// or Error
    }
    m_apartments[roomNumber - 1].Populate(people);
}

std::string Building::GetAdress()
{
    return m_adress;
}

size_t Building::GetCountOfApartments()
{
    return m_countOfApartments;
}

void Building::About()
{
    std::string type = (m_type == House)? "House" : "Office";
    std::cout << "adress " << m_adress << "\n"
              << "type " << type << "\n"
              << "Count of appartments " << m_countOfApartments << "\n";

    for(size_t i = 0; i < m_apartments.size(); ++i)
    {
        std::cout << "Apartment " << i+1 << "\n";
        m_apartments[i].About();
    }
    std::cout << "\n";
}
