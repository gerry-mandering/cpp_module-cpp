#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "ScalarType.hpp"
#include "StringTrimmer.hpp"
#include "TypeDeterminer.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
  public:
    static void convert(std::string &input);

  private:
    static void convertToChar(std::string &input);
    static void convertToInt(std::string &input);
    static void convertToFloat(std::string &input);
    static void convertToDouble(std::string &input);

  private:
    static bool hasDecimalPoint(float floatNumber);
    static bool hasDecimalPoint(double doubleNumber);

  private:
    static void printPositiveInfinity();
    static void printNegativeInfinity();
    static void printNotANumber();

  private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &other);
};

#endif