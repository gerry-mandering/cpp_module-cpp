#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include "./validator/ArgumentValidator.hpp"
#include "./sorter/DequeSorter.hpp"
#include "./sorter/VectorSorter.hpp"

class PmergeMe
{
  private:
    int mArgc;
    char **mArgv;

  public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();

    void run();

  private:
  void printTime(double time, const std::string &sorterName) const;

  private:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
};

#endif