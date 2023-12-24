#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template < typename T >
class Array
{
  private:
    T *mArray;
    unsigned int mSize;

  public:
    Array();
    ~Array();
    Array(const Array &other);
    Array &operator=(const Array &other);

  public:
    Array(unsigned int n);
    T &operator[](long long index);
    const T &operator[](long long index) const;
    unsigned int size() const;
};

#include "Array.tpp"
#endif