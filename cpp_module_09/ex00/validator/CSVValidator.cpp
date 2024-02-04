#include "CSVValidator.hpp"

const std::string CSVValidator::DEFAULT_HEADER = "date,exchange_rate";

CSVValidator::CSVValidator() {}

CSVValidator::~CSVValidator() {}

CSVValidator::CSVValidator(const CSVValidator &other)
{
    (void)other;
}

CSVValidator &CSVValidator::operator=(const CSVValidator &other)
{
    (void)other;
    return *this;
}

bool CSVValidator::isHeaderValid(const std::string &header)
{
    return header == CSVValidator::DEFAULT_HEADER;
}

bool CSVValidator::isValid(const std::string &line)
{
    // check line has comma
    std::string::size_type pos = line.find(',');
    if (std::string::npos == pos)
    {
        throw std::invalid_argument("Invalid CSV file");
    }

    // extract date and validate
    std::string date = StringTrimmer::trim(line.substr(0, pos));
    if (isDateValid(date) == false)
    {
        throw std::invalid_argument("Invalid CSV file");
    }

    // extract exchangeRate and validate
    std::string exchangeRate = StringTrimmer::trim(line.substr(pos + 1));
    if (isExchangeRateValid(exchangeRate) == false)
    {
        throw std::invalid_argument("Invalid CSV file");
    }

    return true;
}

bool CSVValidator::isExchangeRateValid(const std::string &exchangeRateStr)
{
    // check if exchangeRate is empty
    if (exchangeRateStr.empty())
    {
        return false;
    }

    // check if exchangeRate contains only digits and '.'
    if (exchangeRateStr.find_first_not_of("0123456789.") != std::string::npos)
    {
        return false;
    }

    char *endptr;
    double exchangeRate = std::strtod(exchangeRateStr.c_str(), &endptr);

    // check if there are any characters left
    if (*endptr != '\0')
    {
        return false;
    }

    // no conversion could be performed
    if (exchangeRate == 0 && errno == EINVAL)
    {
        return false;
    }

    // exchangeRate is out of double range
    if ((exchangeRate == HUGE_VAL || exchangeRate == -HUGE_VAL) && errno == ERANGE)
    {
        return false;
    }

    return true;
}
