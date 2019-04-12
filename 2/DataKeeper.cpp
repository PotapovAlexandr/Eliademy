#include "DataKeeper.h"
#include  <algorithm>

DataKeeper::DataKeeper():
    m_data(nullptr),
    m_size(0)
{}

DataKeeper::DataKeeper(const uint8_t *data, size_t size)
{
    m_data = new uint8_t[size];
    try
    {
        std::copy(data, data + size, m_data);
    }
    catch(const std::exception /*ex*/)
    {
        delete[] m_data;
        throw;
    }
    m_size = size;
}

DataKeeper::~DataKeeper()
{
    if(m_data != nullptr)
    {
        delete[] m_data;
    }
}

void DataKeeper::Set(const uint8_t *data, size_t size)
{
    uint8_t *tempData = new uint8_t[size];
    try
    {
        std::copy(data, data + size, tempData);
    }
    catch(const std::exception /*ex*/)
    {
        delete[] tempData;
        throw;
    }

    std::swap(tempData, m_data);
    m_size = size;
    delete[] tempData;
}

void DataKeeper::Add(uint8_t *data, size_t size)
{
    size_t newSize = m_size + size;
    uint8_t *tempData = new uint8_t[newSize];
    try
    {
        std::copy(m_data, m_data + m_size, tempData);
        std::copy(data, data + size, tempData + m_size);
    }
    catch(const std::exception /*ex*/)
    {
        delete[] tempData;
        throw;
    }

    std::swap(tempData, m_data);
    m_size = newSize;
    delete[] tempData;
}

const uint8_t *DataKeeper::Get() const
{
    if (m_size == 0)
    {
        return nullptr;
    }
    else
    {
        uint8_t *tempData = new uint8_t[m_size];
        try
        {
            std::copy(m_data, m_data + m_size, tempData);
        }
        catch(const std::exception /*ex*/)
        {
            delete[] tempData;
            throw;
        }

        return tempData;
    }
}

size_t DataKeeper::Size() const
{
    return m_size;
}
