#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T, typename F >
void iter(T *array, size_t length, F fp)
{
    if (array == NULL || fp == NULL)
    {
        return;
    }

    for (size_t i = 0; i < length; ++i)
    {
        fp(array[i]);
    }
}

template < typename T >
void printElement(T &element)
{
    std::cout << element << ' ';
}

#endif