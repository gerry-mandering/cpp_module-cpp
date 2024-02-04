#include "ArgumentValidator.hpp"

ArgumentValidator::ArgumentValidator() {}

ArgumentValidator::~ArgumentValidator() {}

ArgumentValidator::ArgumentValidator(const ArgumentValidator &other)
{
    (void)other;
}

ArgumentValidator &ArgumentValidator::operator=(const ArgumentValidator &other)
{
    (void)other;
    return *this;
}

bool ArgumentValidator::isPositiveInteger(const std::string &arg)
{
    char *endptr;
    long longNumber = std::strtol(arg.c_str(), &endptr, 10);

    // endptr is not pointing to the null character
    if (*endptr != '\0')
    {
        return false;
    }

    // no conversion could be performed
    if (longNumber == 0 && errno == EINVAL)
    {
        return false;
    }

    // longNumber is out of positive integer range
    if (longNumber < 1 || longNumber > std::numeric_limits< int >::max())
    {
        return false;
    }

    return true;
}

bool ArgumentValidator::validate(int argc, char **argv)
{
    if (argc < 2)
    {
        return false;
    }

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);

        if (arg.empty())
        {
            return false;
        }

        if (arg.find_first_not_of("0123456789") != std::string::npos)
        {
            return false;
        }

        if (!isPositiveInteger(arg))
        {
            return false;
        }
    }

    return true;
}