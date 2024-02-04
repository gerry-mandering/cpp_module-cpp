#ifndef DEQUESORTER_HPP
#define DEQUESORTER_HPP

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <iostream>

class DequeSorter
{
  private:
    typedef std::deque< int >::iterator Iterator;

    static const int SEQUENCE_LENGTH = 31;
    static const int JACOBSTHAL_NUMBERS[SEQUENCE_LENGTH];

  private:
    int mArgc;
    char **mArgv;

    std::deque< int > mNumbers;

  public:
    DequeSorter(int argc, char **argv);
    ~DequeSorter();

    double run();

  private:
    void initializeNumbers();

    void fordJohnsonSort(int sizeOfSingleGroup);

    void divideAndSwap(int sizeOfSingleGroup);
    void swapGroup(Iterator front, Iterator back, int sizeOfSingleGroup);

    void createMainAndSubChain(std::deque< Iterator > &mainChain, std::deque< Iterator > &subChain,
                               int sizeOfSingleGroup);

    void mergeChains(std::deque< Iterator > &mainChain, std::deque< Iterator > &subChain);
    int calculateSearchLength(int loopDepth, std::deque< Iterator > &mainChain);
    std::deque< Iterator >::iterator findInsertionLocation(std::deque< Iterator >::iterator start,
                                                           std::deque< Iterator >::iterator end, Iterator target);
    std::deque< Iterator >::iterator binaryInsertion(std::deque< Iterator >::iterator start,
                                                     std::deque< Iterator >::iterator end, Iterator target);

    void updateNumbers(std::deque< Iterator > &mainChain, int sizeOfSingleGroup);

    void printDeque(const std::string &label) const;

    void checkAscendingOrder() const;

  private:
    DequeSorter();
    DequeSorter(const DequeSorter &other);
    DequeSorter &operator=(const DequeSorter &other);
};

#endif
