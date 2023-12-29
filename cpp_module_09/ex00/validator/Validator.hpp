#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include "../util/StringTrimmer.hpp"
#include <string>
#include <cstdlib>
#include <sstream>

class Validator
{
  private:
    static const int MIN_VALID_YEAR;
    static const int MAX_VALID_YEAR;

  public:
    virtual ~Validator();
    virtual bool isHeaderValid(const std::string &header) = 0;
    virtual bool isValid(const std::string &line) = 0;

  protected:
    Validator();

  protected:
    bool isDateValid(const std::string &date);
    bool isLeapYear(int year);

  private:
    Validator(const Validator &other);
    Validator &operator=(const Validator &other);
};

#endif