#ifndef EXPRESSIONVALIDATOR_HPP
#define EXPRESSIONVALIDATOR_HPP

#include <string>
#include <sstream>
#include <cstdlib>

class ExpressionValidator
{
  public:
    static bool validate(const std::string &expression);

  private:
    ExpressionValidator();
    ~ExpressionValidator();
    ExpressionValidator(const ExpressionValidator &other);
    ExpressionValidator &operator=(const ExpressionValidator &other);
};

#endif