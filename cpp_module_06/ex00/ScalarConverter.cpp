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
    std::string trimmedInput = StringTrimmer::trim(input);
    ScalarType type = TypeDeterminer::determineType(trimmedInput);

    switch (type)
    {
        case INVALID:
            std::cout << "Invalid input" << std::endl;
            break;
        case CHAR:
            convertToChar(trimmedInput);
            break;
        case INT:
            convertToInt(trimmedInput);
            break;
        case FLOAT:
            convertToFloat(trimmedInput);
            break;
        case DOUBLE:
            convertToDouble(trimmedInput);
            break;
        default:
            break;
    }
}

void ScalarConverter::convertToChar(std::string &input)
{
    char character = input[0];
    std::cout << "char: '" << character << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(character) << std::endl;
    std::cout << "float: " << static_cast<float>(character) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(character) << ".0" << std::endl;
}

void ScalarConverter::convertToInt(std::string &input)
{
    int intNumber = std::strtol(input.c_str(), NULL, 10);

    char character = static_cast<char>(intNumber);
    float floatNumber = static_cast<float>(intNumber);
    double doubleNumber = static_cast<double>(intNumber);

    if (isprint(intNumber)) {
        std::cout << "char: '" << character << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
    std::cout << "int: " << intNumber << std::endl;
    std::cout << "float: " << floatNumber << ".0f" << std::endl;
    std::cout << "double: " << doubleNumber << ".0" << std::endl;
}

void ScalarConverter::convertToFloat(std::string &input)
{
    float floatNumber = std::strtof(input.c_str(), NULL);

    char character = static_cast<char>(floatNumber);
    int intNumber = static_cast<int>(floatNumber);
    double doubleNumber = static_cast<double>(floatNumber);

    if (input == "-inff") {
        printNegativeInfinity();
        return ;
    } else if (input == "+inff") {
        printPositiveInfinity();
        return ;
    } else if (input == "nanf") {
        printNotANumber();
        return ;
    }

    std::cout << "char: '" << character << "'" << std::endl;
    std::cout << "int: " << intNumber << std::endl;
    if (floatNumber - intNumber == 0.0f) {
        std::cout << "float: " << floatNumber << ".0f" << std::endl;
    } else {
        std::cout << "float: " << floatNumber << "f" << std::endl;
    }
    std::cout << "double: " << doubleNumber << std::endl;
}

void ScalarConverter::convertToDouble(std::string &input)
{
    double doubleNumber = std::strtod(input.c_str(), NULL);

    char character = static_cast<char>(doubleNumber);
    int intNumber = static_cast<int>(doubleNumber);
    float floatNumber = static_cast<float>(doubleNumber);

    if (input == "-inf") {
        printNegativeInfinity();
        return ;
    } else if (input == "+inf") {
        printPositiveInfinity();
        return ;
    } else if (input == "nan") {
        printNotANumber();
        return ;
    }

    std::cout << "char: '" << character << "'" << std::endl;
    std::cout << "int: " << intNumber << std::endl;
    if(doubleNumber - intNumber == 0.0) {
        std::cout << "float: " << floatNumber << ".0f" << std::endl;
    } else {
        std::cout << "float: " << floatNumber << "f" << std::endl;
    }
    std::cout << "double: " << doubleNumber << std::endl;
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