#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <exception>
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
    typedef std::vector< int >::iterator iterator;
    typedef std::vector< int >::const_iterator const_iterator;

  public:
    std::vector< int >::iterator begin();
    std::vector< int >::const_iterator begin() const;
    std::vector< int >::iterator end();
    std::vector< int >::const_iterator end() const;

  public:
    template < class InputIt >
    void addNumber(std::vector<int>::const_iterator pos, InputIt first, InputIt last)
    {
        int insertSize = std::distance(first, last);
        int remainingSize = mSize - mContainer.size();
        if (insertSize > remainingSize)
        {
            throw Span::ContainerFullException();
        }

        mContainer.insert(pos, first, last);
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
