#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "NotFoundException.hpp"
#include <algorithm>

template < typename T >
typename T::iterator easyfind(T &intContainer, int target)
{
    typename T::iterator iter = std::find(intContainer.begin(), intContainer.end(), target);
    if (iter == intContainer.end())
    {
        throw NotFoundException();
    }

    return iter;
}

template < typename T >
typename T::const_iterator easyfind(const T &intContainer, int target)
{
    typename T::const_iterator iter = std::find(intContainer.begin(), intContainer.end(), target);
    if (iter == intContainer.end())
    {
        throw NotFoundException();
    }

    return iter;
}

#endif