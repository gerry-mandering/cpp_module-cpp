#include "StringTrimmer.hpp"

StringTrimmer::StringTrimmer() {}

StringTrimmer::~StringTrimmer() {}

StringTrimmer::StringTrimmer(StringTrimmer const &other)
{
    (void)other;
}

StringTrimmer &StringTrimmer::operator=(StringTrimmer const &other)
{
    (void)other;
    return (*this);
}

std::string &StringTrimmer::leftTrim(std::string &input)
{
    input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
    return (input);
}

std::string &StringTrimmer::rightTrim(std::string &input)
{
    input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
    return (input);
}

std::string &StringTrimmer::trim(std::string &input)
{
    return (leftTrim(rightTrim(input)));
}