#ifndef TYPEDETERMINER_HPP
#define TYPEDETERMINER_HPP

#include "ScalarType.hpp"
#include <string>
#include <limits>
#include <cerrno>

class TypeDeterminer
{
  public:
    static ScalarType determineType(std::string &input);

  private:
    TypeDeterminer();
    ~TypeDeterminer();
    TypeDeterminer(TypeDeterminer const &other);
    TypeDeterminer &operator=(TypeDeterminer const &other);
};

#endif