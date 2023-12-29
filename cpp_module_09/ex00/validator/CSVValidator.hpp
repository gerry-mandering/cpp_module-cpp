#ifndef CSVVALIDATOR_HPP
#define CSVVALIDATOR_HPP

#include "Validator.hpp"
#include <cstdlib>
#include <cmath>

class CSVValidator : public Validator
{
  private:
    static const std::string DEFAULT_HEADER;

  public:
    bool isHeaderValid(const std::string &header);
    bool isValid(const std::string &line);

  private:
    bool isExchangeRateValid(const std::string &exchangeRateStr);

  public:
    CSVValidator();
    ~CSVValidator();

  private:
    CSVValidator(const CSVValidator &other);
    CSVValidator &operator=(const CSVValidator &other);
};

#endif