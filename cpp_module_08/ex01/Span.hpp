#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iterator>
#include <vector>

class Span
{
  private:
    std::vector< int > mContainer;
    unsigned int mSize;

  public:
    Span();
    ~Span();
    Span(const Span &span);
    Span &operator=(const Span &span);

  public:
    Span(unsigned int size);
    void addNumber(int number);
    long long shortestSpan();
    long long longestSpan();

  public:
    std::vector< int >::iterator begin();
    std::vector< int >::const_iterator begin() const;
    std::vector< int >::iterator end();
    std::vector< int >::const_iterator end() const;
    template < class InputIt >
    std::vector< int >::iterator insert(std::vector<int>::const_iterator pos, InputIt first, InputIt last)
    {
        int distance = std::distance(first, last);
        if (distance > static_cast<int>(mSize - mContainer.size()))
        {
            throw ContainerFullException();
        }

        return mContainer.insert(pos, first, last);
    }

  public:
    class ContainerFullException : public std::exception
    {
        const char *what() const throw();
    };

    class NotEnoughElementsException : public std::exception
    {
        const char *what() const throw();
    };
};

#endif
