#include "ExpressionValidator.hpp"

ExpressionValidator::ExpressionValidator() {}

ExpressionValidator::~ExpressionValidator() {}

ExpressionValidator::ExpressionValidator(const ExpressionValidator &other)
{
    (void)other;
}

ExpressionValidator &ExpressionValidator::operator=(const ExpressionValidator &other)
{
    (void)other;
    return *this;
}

bool ExpressionValidator::validate(const std::string &expression)
{
    if (expression.empty())
    {
        return false;
    }

    if (expression.find_first_not_of("0123456789+-*/% ") != std::string::npos)
    {
        return false;
    }

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "/" || token == "*")
        {
            continue;
        }

        if (token.size() > 1)
        {
            return false;
        }
    }

    return true;
}