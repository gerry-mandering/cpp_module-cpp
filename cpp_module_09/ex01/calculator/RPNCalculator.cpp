#include "RPNCalculator.hpp"

RPNCalculator::RPNCalculator() : mStack() {}

RPNCalculator::~RPNCalculator() {}

RPNCalculator::RPNCalculator(const RPNCalculator &other)
{
    (void)other;
}

RPNCalculator &RPNCalculator::operator=(const RPNCalculator &other)
{
    (void)other;
    return *this;
}

double RPNCalculator::calculate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    double leftOperand, rightOperand, result;

    while (iss >> token)
    {
        if (std::isdigit(token[0]) == true)
        {
            mStack.push(std::atoi(token.c_str()));
        }

        if (token == "+" || token == "-" || token == "/" || token == "*")
        {
            // no operands
            if (mStack.empty() == true)
            {
                throw RPNCalculator::InvalidExpressionException();
            }
            rightOperand = mStack.top();
            mStack.pop();

            // no operands
            if (mStack.empty() == true)
            {
                throw RPNCalculator::InvalidExpressionException();
            }
            leftOperand = mStack.top();
            mStack.pop();

            switch (token[0])
            {
                case '+':
                    mStack.push(leftOperand + rightOperand);
                    break;
                case '-':
                    mStack.push(leftOperand - rightOperand);
                    break;
                case '/':
                    if (rightOperand == 0)
                    {
                        throw RPNCalculator::DivisionByZeroException();
                    }
                    mStack.push(leftOperand / rightOperand);
                    break;
                case '*':
                    mStack.push(leftOperand * rightOperand);
                    break;
                default:
                    break;
            }
        }
    }

    result = mStack.top();
    mStack.pop();

    // ./RPN "1 2"
    if (mStack.empty() == false)
    {
        throw RPNCalculator::InvalidExpressionException();
    }

    return result;
}

const char *RPNCalculator::DivisionByZeroException::what() const throw()
{
    return "Division by zero";
}

const char *RPNCalculator::InvalidExpressionException::what() const throw()
{
    return "Invalid expression";
}