#include "TypeDeterminer.hpp"

TypeDeterminer::TypeDeterminer() {}

TypeDeterminer::~TypeDeterminer() {}

TypeDeterminer::TypeDeterminer(TypeDeterminer const &other)
{
    (void)other;
}

TypeDeterminer &TypeDeterminer::operator=(TypeDeterminer const &other)
{
    (void)other;
    return (*this);
}

ScalarType TypeDeterminer::determineType(std::string &input)
{
    // checking for char
    if (input.length() == 1 && !isdigit(input[0]))
    {
        return CHAR;
    }

    // checking for pseudo-literals (inff, +inff, nanf, inf, +inf, nan)
    if (input == "-inff" || input == "+inff" || input == "nanf")
    {
        return FLOAT;
    }
    if (input == "-inf" || input == "+inf" || input == "nan")
    {
        return DOUBLE;
    }

    // checking for int
    char *endptr;
    long longNumber = std::strtol(input.c_str(), &endptr, 10);

    // no conversion could be performed
    if (longNumber == 0 && errno == EINVAL)
    {
        return INVALID;
    }

    if (*endptr == '\0')
    {
        if ((longNumber >= std::numeric_limits<int>::lowest() && longNumber <= std::numeric_limits<int>::max()))
        {
            return INT;
        }
        else
        {
            return INVALID;
        }
    }
    else if (*endptr != '.')
    {
        return INVALID;
    }

    // checking for float
    double doubleNumber = std::strtod(input.c_str(), &endptr);

    // no conversion could be performed
    if (doubleNumber == 0 && errno == EINVAL)
    {
        return INVALID;
    }

    // checking double overflow
    if (*endptr == '\0' && (doubleNumber == HUGE_VAL || doubleNumber == -HUGE_VAL) && errno == ERANGE)
    {
        return INVALID;
    }

    // checking for double
    if (*endptr == '\0')
    {
        return DOUBLE;
    }

    // checking for float
    if (((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0') && (doubleNumber >= std::numeric_limits<float>::lowest() && doubleNumber <= std::numeric_limits<float>::max()))
    {
        return FLOAT;
    }

    return INVALID;
}