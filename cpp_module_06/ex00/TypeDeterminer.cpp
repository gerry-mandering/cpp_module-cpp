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

ScalarType TypeDeterminer::determineType(const std::string &input)
{
    if (isChar(input))
    {
        return CHAR;
    }
    else if (isFloatPseudoLiteral(input))
    {
        return FLOAT;
    }
    else if (isDoublePseudoLiteral(input))
    {
        return DOUBLE;
    }
    else if (isInt(input))
    {
        return INT;
    }
    else if (isFloat(input))
    {
        return FLOAT;
    }
    else if (isDouble(input))
    {
        return DOUBLE;
    }
    return INVALID;
}

bool TypeDeterminer::isChar(const std::string &input)
{
    return input.length() == 1 && !isdigit(input[0]);
}

bool TypeDeterminer::isFloatPseudoLiteral(const std::string &input)
{
    static const char *pseudoLiterals[] = {"inff", "+inff", "-inff", "nanf", "+nanf", "-nanf"};

    for (int i = 0; i < 6; ++i)
    {
        if (input == pseudoLiterals[i])
        {
            return true;
        }
    }
    return false;
}

bool TypeDeterminer::isDoublePseudoLiteral(const std::string &input)
{
    static const char *pseudoLiterals[] = {"inf", "+inf", "-inf", "nan", "+nan", "-nan"};

    for (int i = 0; i < 6; ++i)
    {
        if (input == pseudoLiterals[i])
        {
            return true;
        }
    }
    return false;
}

bool TypeDeterminer::isInt(const std::string &input)
{
    char *endptr;
    long longNumber = std::strtol(input.c_str(), &endptr, 10);

    // no conversion could be performed
    if (longNumber == 0 && errno == EINVAL)
    {
        return false;
    }

    // longNumber is out of integer range
    if (longNumber < std::numeric_limits< int >::lowest() || longNumber > std::numeric_limits< int >::max())
    {
        return false;
    }

    // endptr is not pointing to the null character
    if (*endptr != '\0')
    {
        return false;
    }

    return true;
}

bool TypeDeterminer::isFloat(const std::string &input)
{
    char *endptr;
    float floatNumber = std::strtof(input.c_str(), &endptr);

    // no conversion could be performed
    if (floatNumber == 0 && errno == EINVAL)
    {
        return false;
    }

    // floatNumber is out of float range
    if ((floatNumber == HUGE_VALF || floatNumber == -HUGE_VALF) && errno == ERANGE)
    {
        return false;
    }

    // endptr is not pointing to the 'f' or 'F' character, (endptr + 1) is not pointing to the null character
    if ((*endptr != 'f' && *endptr != 'F') || *(endptr + 1) != '\0')
    {
        return false;
    }

    // comparing the input string with the float boundary values
    if (!BoundaryChecker::isFloat(input.substr(0, input.length() - 1)))
    {
        return false;
    }

    return true;
}

bool TypeDeterminer::isDouble(const std::string &input)
{
    char *endptr;
    double doubleNumber = std::strtod(input.c_str(), &endptr);

    // no conversion could be performed
    if (doubleNumber == 0 && errno == EINVAL)
    {
        return false;
    }

    // doubleNumber is out of double range
    if ((doubleNumber == HUGE_VAL || doubleNumber == -HUGE_VAL) && errno == ERANGE)
    {
        return false;
    }

    // endptr is not pointing to the null character
    if (*endptr != '\0')
    {
        return false;
    }

    // comparing the input string with the double boundary values
    if (!BoundaryChecker::isDouble(input))
    {
        return false;
    }

    return true;
}
