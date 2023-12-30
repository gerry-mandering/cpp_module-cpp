#ifndef RPN_HPP
#define RPN_HPP

#include "./validator/ExpressionValidator.hpp"
#include "./calculator/RPNCalculator.hpp"
#include <iostream>
#include <string>
#include <exception>

class RPN
{
  private:
    std::string mExpression;

  public:
    ~RPN();
    RPN(const std::string &expression);

  public:
    void run();

  private:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
};

#endif