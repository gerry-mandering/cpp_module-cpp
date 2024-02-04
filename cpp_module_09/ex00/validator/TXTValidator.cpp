#include "TXTValidator.hpp"

const std::string TXTValidator::DEFAULT_HEADER = "date | value";

TXTValidator::TXTValidator() {}

TXTValidator::~TXTValidator() {}

TXTValidator::TXTValidator(const TXTValidator &other)
{
    (void)other;
}

TXTValidator &TXTValidator::operator=(const TXTValidator &other)
{
    (void)other;
    return *this;
}

bool TXTValidator::isHeaderValid(const std::string &header)
{
    return header == TXTValidator::DEFAULT_HEADER;
}

bool TXTValidator::isValid(const std::string &line)
{
    // check line has pipe
    std::string::size_type pos = line.find('|');
    if (std::string::npos == pos)
    {
        std::cout << "Error: bad input format => " << line << std::endl;
        return false;
    }

    // extract date and validate
    std::string date = StringTrimmer::trim(line.substr(0, pos));
    if (isDateValid(date) == false)
    {
        std::cout << "Error: invalid date => " << line << std::endl;
        return false;
    }

    // extract value and validate
    std::string value = StringTrimmer::trim(line.substr(pos + 1));
    if (isValueValid(value) == false)
    {
        std::cout << "Error: invalid value => " << line << std::endl;
        return false;
    }

    return true;
}

bool TXTValidator::isValueValid(const std::string &valueStr)
{
    // check if value is empty
    if (valueStr.empty())
    {
        return false;
    }

    // check if value contains only digits
    if (valueStr.find_first_not_of("0123456789.") != std::string::npos)
    {
        return false;
    }

    char *endptr;
    float value = std::strtof(valueStr.c_str(), &endptr);

    // check if there are any characters left
    if (*endptr != '\0')
    {
        return false;
    }

    // no conversion could be performed
    if (value == 0.0f && errno == EINVAL)
    {
        return false;
    }

    // value is out of float range
    if ((value == HUGE_VALF || value == -HUGE_VALF) && errno == ERANGE)
    {
        return false;
    }

    // check value is between 0 and 1000
    if (value < 0.0f || value > 1000.0f)
    {
        return false;
    }

    return true;
}
