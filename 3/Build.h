#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Apartment.h"
#include "Human.h"

using Apartmens_vt = std::vector<Apartment>;

enum BuildingType
{
    House = 1,
    Office
};

class Building
{
public:
    Building(const std::string& adress, int countOfApartments, BuildingType type):
        m_adress(adress),
        m_countOfApartments(countOfApartments),
        m_type(type)
    {
        m_apartments.resize(countOfApartments);

    }
    void PopulateInAppartment(const Humans_vt& people, int roomNumber)
    {
        if (roomNumber > m_countOfApartments)
        {
            return;// or Error
        }
        m_apartments[roomNumber - 1].Populate(people);
    }
    std::string GetAdress()
    {
        return m_adress;
    }
    int GetCountOfApartments()
    {
        return m_countOfApartments;
    }
    void About()
    {
        std::string type = (m_type == House)? "House" : "Office";
        std::cout << "adress " << m_adress << "\n"
                  << "type " << type << "\n"
                  << "Count of appartments " << m_countOfApartments << "\n";

        for(int i = 0; i < m_apartments.size(); ++i)
        {
            std::cout << "Apartment " << i+1 << "\n";
            m_apartments[i].About();
        }
         std::cout << "\n";
    }

private:
    std::string m_adress;
    int m_countOfApartments;
    Apartmens_vt m_apartments;
    BuildingType m_type;
};
