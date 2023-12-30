#ifndef RPNCALCULATOR_HPP
#define RPNCALCULATOR_HPP

#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <exception>

class RPNCalculator
{
  private:
    std::stack<double> mStack;

  public:
    RPNCalculator();
    ~RPNCalculator();

  public:
    double calculate(const std::string &expression);

  private:
    RPNCalculator(const RPNCalculator &other);
    RPNCalculator &operator=(const RPNCalculator &other);

  public:
    class DivisionByZeroException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class InvalidExpressionException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif