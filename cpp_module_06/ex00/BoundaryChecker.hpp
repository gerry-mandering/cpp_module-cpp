#ifndef BOUNDARYCHECKER_HPP
#define BOUNDARYCHECKER_HPP

#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>

class BoundaryChecker
{
  public:
    static bool isFloat(const std::string &input);
    static bool isDouble(const std::string &input);

  private:
    static std::string truncateAfterDecimalPoint(const std::string &input);
    static std::string truncateBeforeDecimalPoint(const std::string &input);

  private:
    static const std::string FLOAT_MIN;
    static const std::string FLOAT_MAX;
    static const std::string DOUBLE_MIN;
    static const std::string DOUBLE_MAX;

  private:
    BoundaryChecker();
    ~BoundaryChecker();
    BoundaryChecker(BoundaryChecker const &other);
    BoundaryChecker &operator=(BoundaryChecker const &other);
};

#endif