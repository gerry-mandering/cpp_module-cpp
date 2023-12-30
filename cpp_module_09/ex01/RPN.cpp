#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
    (void)other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

RPN::RPN(const std::string &expression) : mExpression(expression) {}

void RPN::run()
{
    if (ExpressionValidator::validate(mExpression) == false)
    {
        std::cerr << "Error: Invalid expression" << std::endl;
        return;
    }

    try
    {
        RPNCalculator calculator;
        std::cout << calculator.calculate(mExpression) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}