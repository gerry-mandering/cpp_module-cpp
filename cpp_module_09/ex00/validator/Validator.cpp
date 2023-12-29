#include "Validator.hpp"

const int Validator::MIN_VALID_YEAR = 0;
const int Validator::MAX_VALID_YEAR = 9999;

Validator::Validator() {}

Validator::~Validator() {}

Validator::Validator(const Validator &other)
{
    (void)other;
}

Validator &Validator::operator=(const Validator &other)
{
    (void)other;
    return *this;
}

bool Validator::isDateValid(const std::string &date)
{
    if (date.empty())
    {
        return false;
    }

    std::stringstream dateStream(date);
    std::string yearStr, monthStr, dayStr;
    int year, month, day;

    // split date by '-'
    std::getline(dateStream, yearStr, '-');
    std::getline(dateStream, monthStr, '-');
    std::getline(dateStream, dayStr);

    // check year, month, day is not empty
    if (yearStr.empty() || monthStr.empty() || dayStr.empty())
    {
        return false;
    }

    // check year, month, day contains only digits
    if (yearStr.find_first_not_of("0123456789") != std::string::npos ||
        monthStr.find_first_not_of("0123456789") != std::string::npos ||
        dayStr.find_first_not_of("0123456789") != std::string::npos)
    {
        return false;
    }

    // convert year, month, day to int
    year = std::atoi(yearStr.c_str());
    month = std::atoi(monthStr.c_str());
    day = std::atoi(dayStr.c_str());

    // check year, month, day is valid
    if (year < Validator::MIN_VALID_YEAR || year > Validator::MAX_VALID_YEAR)
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    if (day < 1 || day > 31)
    {
        return false;
    }

    // check day is valid for month
    if (month == 2)
    {
        if (isLeapYear(year))
        {
            return day <= 29;
        }
        else
        {
            return day <= 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return day <= 30;
    }

    return true;
}

bool Validator::isLeapYear(int year)
{
    if (year % 4 != 0)
    {
        return false;
    }
    else if (year % 100 != 0)
    {
        return true;
    }
    else if (year % 400 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}