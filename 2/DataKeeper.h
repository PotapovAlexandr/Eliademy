#pragma once
#include <iostream>

class DataKeeper
{
public:
    DataKeeper();
    DataKeeper(const uint8_t* data, size_t size);
    ~DataKeeper();

    void Set(const uint8_t* data, size_t size); // Stores given data with given size as copy

    void Add(uint8_t* data, size_t size); // Adds given data to the end of existant data

    const uint8_t* Get() const; // Returns stored data

    size_t Size() const; // Returns the size of the stored data
private:
    uint8_t* m_data;
    size_t m_size;
};
