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

void ScalarConverter::convert(const std::string &input)
{
    ScalarType type = TypeDeterminer::determineType(input);

    switch (type)
    {
        case CHAR:
            convertToChar(input);
            break;
        case INT:
            convertToInt(input);
            break;
        case FLOAT:
            convertToFloat(input);
            break;
        case DOUBLE:
            convertToDouble(input);
            break;
        case INVALID:
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
}

void ScalarConverter::convertToChar(const std::string &input)
{
    char charValue = input[0];
    printConvertedValues(charValue);
}

void ScalarConverter::convertToInt(const std::string &input)
{
    int intValue = std::strtol(input.c_str(), NULL, 10);
    printConvertedValues(intValue);
}

void ScalarConverter::convertToFloat(const std::string &input)
{
    float floatValue = std::strtof(input.c_str(), NULL);

    if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf" || input == "+nanf" ||
        input == "-nanf")
    {
        printPseudoLiteral(input);
        return;
    }

    printConvertedValues(floatValue);
}

void ScalarConverter::convertToDouble(const std::string &input)
{
    double doubleValue = std::strtod(input.c_str(), NULL);

    if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan" || input == "+nan" || input == "-nan")
    {
        printPseudoLiteral(input);
        return;
    }

    printConvertedValues(doubleValue);
}

void ScalarConverter::printPseudoLiteral(const std::string &input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (input == "inff" || input == "+inff" || input == "inf" || input == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (input == "-inff" || input == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (input == "nanf" || input == "nan" || input == "+nanf" || input == "+nan" || input == "-nanf" ||
             input == "-nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void ScalarConverter::printConvertedValues(char charValue)
{
    int intValue = static_cast< int >(charValue);
    float floatValue = static_cast< float >(charValue);
    double doubleValue = static_cast< double >(charValue);

    std::cout << "char: '" << charValue << "'" << std::endl;
    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

void ScalarConverter::printConvertedValues(int intValue)
{
    char charValue = static_cast< char >(intValue);
    float floatValue = static_cast< float >(intValue);
    double doubleValue = static_cast< double >(intValue);

    if (intValue < std::numeric_limits< char >::lowest() || intValue > std::numeric_limits< char >::max())
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

void ScalarConverter::printConvertedValues(float floatValue)
{
    char charValue = static_cast< char >(floatValue);
    int intValue = static_cast< int >(floatValue);
    double doubleValue = static_cast< double >(floatValue);

    if (floatValue < std::numeric_limits< char >::lowest() || floatValue > std::numeric_limits< char >::max())
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

    // numeric_limits로 비교했을때 1차적으로 변환된 floatValue가 2147483648.0f 일때도 int가 impossible이 안 나오는 문제
    // 발생 floatValue가 2147483648.0f 일 때 - floatValue == std::numeric_limits< int >::max() floatValue가
    // -2147483648.0f 일 때 - floatValue == std::numeric_limits< int >::lowest() float binary 표현 -
    // https://www.h-schmidt.net/FloatConverter/IEEE754.html
    if (floatValue < -2147483648.0f || floatValue >= 2147483648.0f)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << intValue << std::endl;
    }

    if (hasDecimalPoint(floatValue))
    {
        std::cout << "float: " << std::fixed << floatValue << "f" << std::endl;
    }
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    }

    if (hasDecimalPoint(doubleValue))
    {
        std::cout << "double: " << std::fixed << doubleValue << std::endl;
    }
    else
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
    }
}

void ScalarConverter::printConvertedValues(double doubleValue)
{
    char charValue = static_cast< char >(doubleValue);
    int intValue = static_cast< int >(doubleValue);
    float floatValue = static_cast< float >(doubleValue);

    if (doubleValue < std::numeric_limits< char >::lowest() || doubleValue > std::numeric_limits< char >::max())
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

    if (doubleValue < std::numeric_limits< int >::lowest() || doubleValue > std::numeric_limits< int >::max())
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << intValue << std::endl;
    }

    if (doubleValue > std::numeric_limits< float >::max() || doubleValue < std::numeric_limits< float >::lowest())
    {
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        if (hasDecimalPoint(floatValue))
        {
            std::cout << "float: " << std::fixed << floatValue << "f" << std::endl;
        }
        else
        {
            std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
        }
    }

    if (hasDecimalPoint(doubleValue))
    {
        std::cout << "double: " << std::fixed << doubleValue << std::endl;
    }
    else
    {
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
