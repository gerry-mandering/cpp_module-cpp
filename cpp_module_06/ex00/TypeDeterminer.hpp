#ifndef TYPEDETERMINER_HPP
#define TYPEDETERMINER_HPP

#include "ScalarType.hpp"
#include "StringTrimmer.hpp"
#include <string>
#include <limits>
#include <cerrno>
#include <iostream>

class TypeDeterminer
{
  public:
    static ScalarType determineType(std::string &input);

  private:
    static bool isChar(const std::string &input);
    static bool isFloatPseudoLiteral(const std::string &input);
    static bool isDoublePseudoLiteral(const std::string &input);
    static bool isInt(const std::string &input);
    static bool isFloat(const std::string &input);
    static bool isDouble(const std::string &input);

  private:
    TypeDeterminer();
    ~TypeDeterminer();
    TypeDeterminer(TypeDeterminer const &other);
    TypeDeterminer &operator=(TypeDeterminer const &other);
};

#endif