#ifndef PTRVECTOR_H
#define PTRVECTOR_H
#include <vector>
#include <memory>
//#include <utility>

template<class T>
class PtrVector
{
public:
    PtrVector(){}

    PtrVector(const std::vector<std::shared_ptr<T>>& otherVector)
    {
        for(std::shared_ptr<T> elem : otherVector)
        {
            m_storage.emplace_back(new T (*(elem.get())));
        }
    }

    ~PtrVector()
    {}

    PtrVector(const PtrVector& other)
    {
        PtrVector temp(other.m_storage);

        Swap(temp);
    }

    const PtrVector operator=(const PtrVector& other)
    {
        PtrVector temp(other.m_storage);

        Swap(temp);
        return *this;
    }
    void Add(T* p) // Takes ownership of the p
    {
        m_storage.emplace_back(std::shared_ptr<T>(p));
        p = nullptr;
    }

    T &Get(size_t index)
    {
        return *m_storage.at(index).get();
    }

    const T& Get(size_t index) const
    {
        return (m_storage.at(index).get());
    }

    void Clear()
    {
        m_storage.clear();
    }

    size_t Size() const
    {
        return m_storage.size();
    }
private:
    void Swap(PtrVector& right)
    {
        std::swap(m_storage, right.m_storage);
    }
private:
    std::vector<std::shared_ptr<T>> m_storage;
};

#endif // PTRVECTOR_H
