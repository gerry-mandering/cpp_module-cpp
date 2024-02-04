#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

PmergeMe::PmergeMe(int argc, char **argv) : mArgc(argc), mArgv(argv) {}

void PmergeMe::run()
{
    if (ArgumentValidator::validate(mArgc, mArgv) == false)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    double vectorSorterTime, dequeSorterTime;

    VectorSorter vectorSorter(mArgc, mArgv);
    DequeSorter dequeSorter(mArgc, mArgv);

    vectorSorterTime = vectorSorter.run();
    dequeSorterTime = dequeSorter.run();

    printTime(vectorSorterTime, "std::vector");
    printTime(dequeSorterTime, "std::deque");
}

void PmergeMe::printTime(double time, const std::string &sorterName) const
{
    std::cout << "Time to process a range of " << mArgc - 1 << " elements with " << sorterName << " : " << time << " us"
              << std::endl;
}