#pragma once
#include <vector>
#include <memory>
#include "Human.h"


using HumanGuard = std::shared_ptr<Human>;
using Humans_vt = std::vector<HumanGuard>; // Family or Employees

struct Apartment
{
    Apartment(){}
    explicit Apartment(const Humans_vt& tenants)
    {
        m_tenants.reserve(tenants.size());
        m_tenants.insert(m_tenants.begin(), tenants.begin(), tenants.end());
    }
    void Populate(const Humans_vt& newTenants)
    {
        m_tenants.clear();
        m_tenants.reserve(newTenants.size());
        m_tenants.insert(m_tenants.begin(), newTenants.begin(), newTenants.end());
    }
    void About()
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
private:
    Humans_vt m_tenants;
};
