#pragma once
#include <QDate>

class Human
{
public:
    Human(const QDate& bdata, const std::string& name):
        m_birthdayDate(bdata),
        m_name(name)
    {}
    QDate GetBithday()
    {
       return m_birthdayDate;
    }
    void AboutMe()
    {
        std::cout << "Name" << m_name << "\n"
                  << "Birthday " << m_birthdayDate.toString("dd.MM.yyyy").toStdString() << "\n";
    }
private:
    QDate m_birthdayDate;
    std::string m_name;
};


class Man: public Human
{
public:
    Man(const QDate& bdata, const std::string& name):Human(bdata, name){}
    void AboutMe()
    {
        std::cout << "Man";
        Human::AboutMe();
    }
};

class Woman: public Human
{
public:
    Woman(const QDate& bdata, const std::string& name):Human(bdata, name){}
    void AboutMe()
    {
        std::cout << "Woman";
        Human::AboutMe();
    }
};
