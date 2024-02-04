#ifndef ARGUMENTVALIDATOR_HPP
#define ARGUMENTVALIDATOR_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cerrno>

class ArgumentValidator
{
  public:
    static bool validate(int argc, char **argv);

  private:
    static bool isPositiveInteger(const std::string &arg);

  private:
    ArgumentValidator();
    ~ArgumentValidator();
    ArgumentValidator(const ArgumentValidator &other);
    ArgumentValidator &operator=(const ArgumentValidator &other);
};

#endif