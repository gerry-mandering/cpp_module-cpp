#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "ScalarType.hpp"
#include "TypeDeterminer.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter
{
  public:
    static void convert(const std::string &input);

  private:
    static void convertToChar(const std::string &input);
    static void convertToInt(const std::string &input);
    static void convertToFloat(const std::string &input);
    static void convertToDouble(const std::string &input);

  private:
    static void printPseudoLiteral(const std::string &input);
    static void printConvertedValues(char charValue);
    static void printConvertedValues(int intValue);
    static void printConvertedValues(float floatValue);
    static void printConvertedValues(double doubleValue);

  private:
    static bool hasDecimalPoint(float floatNumber);
    static bool hasDecimalPoint(double doubleNumber);

  private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &other);
};

#endif