#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cmath>
#include <iostream>
#include <vector>

class PmergeMe
{
  private:
    typedef std::vector< int >::iterator Iterator;
    static const int ARRAY_SIZE = 31;
    static const int jacobsthal[ARRAY_SIZE];

  private:
    int mArgc;
    char **mArgv;
    std::vector< int > v;

  public:
    ~PmergeMe();

  public:
    PmergeMe(int argc, char **argv);
    void run();

  private:
    void printVector() const;
    void swapGroup(Iterator front, Iterator back, int groupSize);
    std::vector< Iterator >::iterator binaryInsertion(std::vector< Iterator >::iterator start, std::vector< Iterator >::iterator end, Iterator target);
    void fordJohnsonSort(int groupSize);

  private:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
};

#endif