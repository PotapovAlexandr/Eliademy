#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <QDate>
#include <memory>

class Human
{
public:
    Human(const QDate& bdata, const std::string& name);
    QDate GetBithday();
    void AboutMe();
private:
    QDate m_birthdayDate;
    std::string m_name;
};

class Man: public Human
{
public:
    Man(const QDate& bdata, const std::string& name);
    void AboutMe();
};

class Woman: public Human
{
public:
    Woman(const QDate& bdata, const std::string& name);
    void AboutMe();
};

using HumanGuard = std::shared_ptr<Human>;
using Humans_vt = std::vector<HumanGuard>; // Family or Employees

struct Apartment
{
    Apartment();
    explicit Apartment(const Humans_vt& tenants);
    void Populate(const Humans_vt& newTenants);
    void About();
private:
    Humans_vt m_tenants;
};
using Apartmens_vt = std::vector<Apartment>;

enum BuildingType
{
    House = 1,
    Office
};

class Building
{
public:
    Building(const std::string& adress, size_t countOfApartments, BuildingType type);
    void PopulateInAppartment(const Humans_vt& people, size_t roomNumber);
    std::string GetAdress();
    size_t GetCountOfApartments();
    void About();

private:
    std::string m_adress;
    size_t m_countOfApartments;
    Apartmens_vt m_apartments;
    BuildingType m_type;
};
