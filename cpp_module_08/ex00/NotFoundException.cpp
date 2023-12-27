#include "NotFoundException.hpp"

const char *NotFoundException::what() const throw()
{
    return "Target Not found";
}