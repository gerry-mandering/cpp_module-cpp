#include "MutantStack.hpp"

template < typename T >
typename MutantStack< T >::iterator MutantStack< T >::begin()
{
    return c.begin();
}

template < typename T >
typename MutantStack< T >::iterator MutantStack< T >::end()
{
    return c.end();
}

template < typename T >
typename MutantStack< T >::const_iterator MutantStack< T >::begin() const
{
    return c.begin();
}

template < typename T >
typename MutantStack< T >::const_iterator MutantStack< T >::end() const
{
    return c.end();
}

template < typename T >
typename MutantStack< T >::reverse_iterator MutantStack< T >::rbegin()
{
    return c.rbegin();
}

template < typename T >
typename MutantStack< T >::reverse_iterator MutantStack< T >::rend()
{
    return c.rend();
}

template < typename T >
typename MutantStack< T >::const_reverse_iterator MutantStack< T >::rbegin() const
{
    return c.rbegin();
}

template < typename T >
typename MutantStack< T >::const_reverse_iterator MutantStack< T >::rend() const
{
    return c.rend();
}

template < typename T >
MutantStack< T >::MutantStack() : std::stack< T >()
{
}

template < typename T >
MutantStack< T >::~MutantStack()
{
}

template < typename T >
MutantStack< T >::MutantStack(const MutantStack &other) : std::stack< T >(other)
{
}

template < typename T >
MutantStack< T > &MutantStack< T >::operator=(const MutantStack &other)
{
    if (this != &other)
    {
        std::stack< T >::operator=(other);
    }
    return *this;
}
