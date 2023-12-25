#ifndef NOTFOUNDEXCEPTION_HPP
#define NOTFOUNDEXCEPTION_HPP

#include <exception>

class NotFoundException : public std::exception
{
    const char *what() const throw();
};

#endif