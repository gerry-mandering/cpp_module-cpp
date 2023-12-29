#include "StringTrimmer.hpp"

StringTrimmer::StringTrimmer() {}

StringTrimmer::~StringTrimmer() {}

StringTrimmer::StringTrimmer(const StringTrimmer &other)
{
    (void)other;
}

StringTrimmer &StringTrimmer::operator=(const StringTrimmer &other)
{
    (void)other;
    return *this;
}

std::string StringTrimmer::trim(const std::string &str)
{
    std::string::size_type first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    std::string::size_type last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}