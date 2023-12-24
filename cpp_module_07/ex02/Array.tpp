#include "Array.hpp"

template < typename T >
Array< T >::Array() : mArray(NULL), mSize(0)
{
}

template < typename T >
Array< T >::~Array()
{
    delete[] mArray;
}

template < typename T >
Array< T >::Array(const Array &other) : mArray(NULL), mSize(0)
{
    *this = other;
}

template < typename T >
Array< T > &Array< T >::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] mArray;

        mSize = other.mSize;
        mArray = new T[mSize];

        for (unsigned int i = 0; i < mSize; ++i)
        {
            mArray[i] = other.mArray[i];
        }
    }

    return *this;
}

template < typename T >
Array< T >::Array(unsigned int n) : mArray(new T[n]), mSize(n)
{
}

template < typename T >
T &Array< T >::operator[](long long index)
{
    if (index < 0 || index >= mSize)
    {
        throw std::out_of_range("Index is out of range.");
    }

    return mArray[index];
}

template < typename T >
const T &Array< T >::operator[](long long index) const
{
    if (index < 0 || index >= mSize)
    {
        throw std::out_of_range("Index is out of range.");
    }

    return mArray[index];
}

template < typename T >
unsigned int Array< T >::size() const
{
    return mSize;
}
