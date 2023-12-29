#ifndef TXTVALIDATOR_HPP
#define TXTVALIDATOR_HPP

#include "Validator.hpp"
#include <iostream>

class TXTValidator : public Validator
{
  private:
    static const std::string DEFAULT_HEADER;

  public:
    bool isHeaderValid(const std::string &header);
    bool isValid(const std::string &line);

  private:
    bool isValueValid(const std::string &valueStr);

  public:
    TXTValidator();
    ~TXTValidator();

  private:
    TXTValidator(const TXTValidator &other);
    TXTValidator &operator=(const TXTValidator &other);
};

#endif