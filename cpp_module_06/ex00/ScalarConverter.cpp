#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    (void)other;
    return (*this);
}

void ScalarConverter::convert(std::string &input)
{
    ScalarType type = TypeDeterminer::determineType(input);

    switch (type)
    {
        case INVALID:
            std::cout << "Invalid input" << std::endl;
            break;
        case CHAR:
            convertToChar(input);
            break;
        case INT:
            convertToInt(input);
            break;
        case FLOAT:
            convertToFloat(input);
            break;
            //        case DOUBLE:
            //            convertToDouble(input);
            //            break;
        default:
            break;
    }
}

void ScalarConverter::convertToChar(std::string &input)
{
    char charValue = input[0];
    int intValue = static_cast< int >(charValue);
    float floatValue = static_cast< float >(charValue);
    double doubleValue = static_cast< double >(charValue);

    std::cout << "char: '" << charValue << "'" << std::endl;
    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

void ScalarConverter::convertToInt(std::string &input)
{
    int intValue = std::strtol(input.c_str(), NULL, 10);
    char charValue = static_cast< char >(intValue);
    float floatValue = static_cast< float >(intValue);
    double doubleValue = static_cast< double >(intValue);

    if (intValue < -128 || intValue > 127)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (std::isprint(charValue))
    {
        std::cout << "char: '" << charValue << "'" << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

void ScalarConverter::convertToFloat(std::string &input)
{
    double floatValue = std::strtod(input.c_str(), NULL);
    char charValue = static_cast< char >(floatValue);
    int intValue = static_cast< int >(floatValue);
    double doubleValue = static_cast< double >(floatValue);

    if (floatValue < -128.0 || floatValue > 127.0)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (std::isprint(charValue))
    {
        std::cout << "char: '" << charValue << "'" << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }

    if (

    if (hasDecimalPoint(floatValue))
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
    }
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
    }
}

bool ScalarConverter::hasDecimalPoint(float floatNumber)
{
    float intPart;
    float fracPart = std::modf(floatNumber, &intPart);
    return fracPart != 0.0f;
}

bool ScalarConverter::hasDecimalPoint(double doubleNumber)
{
    double intPart;
    double fracPart = std::modf(doubleNumber, &intPart);
    return fracPart != 0.0;
}

void ScalarConverter::printPositiveInfinity()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
}

void ScalarConverter::printNegativeInfinity()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}

void ScalarConverter::printNotANumber()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}
