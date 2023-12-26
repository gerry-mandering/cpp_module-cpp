#include "Span.hpp"

Span::Span() : mSize(0) {}

Span::~Span() {}

Span::Span(const Span &span)
{
    *this = span;
}

Span &Span::operator=(const Span &span)
{
    if (this != &span)
    {
        mContainer = span.mContainer;
        mSize = span.mSize;
    }

    return *this;
}

Span::Span(unsigned int size) : mSize(size)
{
    mContainer.reserve(size);
}

void Span::addNumber(int number)
{
    if (mContainer.size() == mSize)
    {
        throw Span::ContainerFullException();
    }

    mContainer.push_back(number);
}

long long Span::shortestSpan()
{
    if (mContainer.size() < 2)
    {
        throw Span::NotEnoughElementsException();
    }

    std::vector< int > tmp(mContainer);
    std::sort(tmp.begin(), tmp.end());
    std::vector< int >::iterator iter = tmp.begin();

    long long shortestSpan = llabs(*iter - *(iter + 1));
    iter++;

    for (; iter != tmp.end() - 1; iter++)
    {
        long long span = llabs(*iter - *(iter + 1));
        if (span < shortestSpan)
        {
            shortestSpan = span;
        }
    }

    return shortestSpan;
}

long long Span::longestSpan()
{
    if (mContainer.size() < 2)
    {
        throw Span::NotEnoughElementsException();
    }

    std::vector< int > tmp(mContainer);
    std::sort(tmp.begin(), tmp.end());

    return llabs(tmp.front() - tmp.back());
}

std::vector< int >::iterator Span::begin()
{
    return mContainer.begin();
}

std::vector< int >::const_iterator Span::begin() const
{
    return mContainer.begin();
}

std::vector< int >::iterator Span::end()
{
    return mContainer.end();
}

std::vector< int >::const_iterator Span::end() const
{
    return mContainer.end();
}

const char *Span::ContainerFullException::what() const throw()
{
    return "Container is full";
}

const char *Span::NotEnoughElementsException::what() const throw()
{
    return "Not enough elements";
}