#ifndef VECTORSORTER_HPP
#define VECTORSORTER_HPP

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>

class VectorSorter
{
  private:
    typedef std::vector< int >::iterator Iterator;

    static const int SEQUENCE_LENGTH = 31;
    static const int JACOBSTHAL_NUMBERS[SEQUENCE_LENGTH];

  private:
    int mArgc;
    char **mArgv;

    std::vector< int > mNumbers;

  public:
    VectorSorter(int argc, char **argv);
    ~VectorSorter();

    double run();

  private:
    void initializeNumbers();

    void fordJohnsonSort(int sizeOfSingleGroup);

    void divideAndSwap(int sizeOfSingleGroup);
    void swapGroup(Iterator front, Iterator back, int sizeOfSingleGroup);

    void createMainAndSubChain(std::vector< Iterator > &mainChain, std::vector< Iterator > &subChain,
                               int sizeOfSingleGroup);

    void mergeChains(std::vector< Iterator > &mainChain, std::vector< Iterator > &subChain);
    int calculateSearchLength(int loopDepth, std::vector< Iterator > &mainChain);
    std::vector< Iterator >::iterator findInsertionLocation(std::vector< Iterator >::iterator start,
                                                            std::vector< Iterator >::iterator end, Iterator target);
    std::vector< Iterator >::iterator binaryInsertion(std::vector< Iterator >::iterator start,
                                                      std::vector< Iterator >::iterator end, Iterator target);

    void updateNumbers(std::vector< Iterator > &mainChain, int sizeOfSingleGroup);

    void printVector(const std::string &label) const;

    void checkAscendingOrder() const;

  private:
    VectorSorter();
    VectorSorter(const VectorSorter &other);
    VectorSorter &operator=(const VectorSorter &other);
};

#endif