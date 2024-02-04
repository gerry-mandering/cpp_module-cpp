#include "VectorSorter.hpp"

const int VectorSorter::JACOBSTHAL_NUMBERS[VectorSorter::SEQUENCE_LENGTH] = {
    1,       3,        5,        11,       21,       43,        85,        171,       341,       683,     1365,
    2731,    5461,     10923,    21845,    43691,    87381,     174763,    349525,    699051,    1398101, 2796203,
    5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};

VectorSorter::VectorSorter() {}

VectorSorter::~VectorSorter() {}

VectorSorter::VectorSorter(const VectorSorter &other)
{
    (void)other;
}

VectorSorter &VectorSorter::operator=(const VectorSorter &other)
{
    (void)other;
    return *this;
}

/**
 * @brief Constructor
 */
VectorSorter::VectorSorter(int argc, char **argv) : mArgc(argc), mArgv(argv) {}

/**
 * @brief Run the Ford-Johnson algorithm
 *
 * @return Time to process a range of elements
 */
double VectorSorter::run()
{
    std::cout << "<Vector>" << std::endl;

    clock_t start, end;
    printVector("Before");

    start = clock(); // start time
    initializeNumbers();
    fordJohnsonSort(1);
    end = clock(); // end time

    printVector("After");

    checkAscendingOrder();

    return (end - start) / (CLOCKS_PER_SEC / 1000000);
}

/**
 * @brief Initialize numbers from arguments
 */
void VectorSorter::initializeNumbers()
{
    for (int i = 1; i < mArgc; i++)
    {
        mNumbers.push_back(std::atoi(mArgv[i]));
    }
}

/**
 * @brief Swap group pair
 */
void VectorSorter::swapGroup(Iterator groupBegin, Iterator nextGroupBegin, int sizeOfSingleGroup)
{
    for (int i = 0; i < sizeOfSingleGroup; i++)
    {
        std::iter_swap(groupBegin + i, nextGroupBegin + i);
    }
}

/**
 * @brief Divide numbers into groups and swap group pair by descending order
 */
void VectorSorter::divideAndSwap(int sizeOfSingleGroup)
{
    Iterator groupBegin = mNumbers.begin();
    Iterator nextGroupBegin = groupBegin + sizeOfSingleGroup;

    // loop until there are no more groups to swap
    while (std::distance(groupBegin, mNumbers.end()) >= sizeOfSingleGroup * 2)
    {
        // swap group pair by descending order
        if (*groupBegin < *nextGroupBegin)
        {
            swapGroup(groupBegin, nextGroupBegin, sizeOfSingleGroup);
        }

        // move to next group pair
        groupBegin = nextGroupBegin + sizeOfSingleGroup;
        nextGroupBegin = groupBegin + sizeOfSingleGroup;
    }
}

/**
 * @brief Create main and sub chain
 */
void VectorSorter::createMainAndSubChain(std::vector< Iterator > &mainChain, std::vector< Iterator > &subChain,
                                         int sizeOfSingleGroup)
{
    Iterator mainElement = mNumbers.begin();
    Iterator subElement = mainElement + sizeOfSingleGroup;

    while (std::distance(mainElement, mNumbers.end()) >= sizeOfSingleGroup * 2)
    {
        mainChain.push_back(mainElement);
        subChain.push_back(subElement);

        mainElement = subElement + sizeOfSingleGroup;
        subElement = mainElement + sizeOfSingleGroup;
    }

    // if there is one group left, add it to the sub chain
    if (std::distance(mainElement, mNumbers.end()) >= sizeOfSingleGroup)
    {
        subChain.push_back(mainElement);
    }
}

/**
 * @brief Find insertion location using binary search
 */
std::vector< VectorSorter::Iterator >::iterator VectorSorter::findInsertionLocation(
    std::vector< Iterator >::iterator start, std::vector< Iterator >::iterator end, Iterator target)
{
    std::vector< Iterator >::iterator mid;

    while (start != end)
    {
        mid = start + std::distance(start, end) / 2;

        if (*(*mid) < *target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

/**
 * @brief calculate search length based on loop depth
 */
int VectorSorter::calculateSearchLength(int loopDepth, std::vector< Iterator > &mainChain)
{
    int searchLength = std::pow(2, loopDepth + 1) - 1;

    if (searchLength > static_cast< int >(mainChain.size()))
    {
        searchLength = mainChain.size();
    }

    return searchLength;
}

/**
 * @brief Merge main and sub chain using binary insertion order by Jacobsthal number
 */
void VectorSorter::mergeChains(std::vector< Iterator > &mainChain, std::vector< Iterator > &subChain)
{
    int prevStartIndex = -1;

    for (int i = 0; i < VectorSorter::SEQUENCE_LENGTH; ++i)
    {
        int jacobsthalNumber = JACOBSTHAL_NUMBERS[i];
        int startIndex = std::min(jacobsthalNumber, static_cast< int >(subChain.size())) - 1;

        for (int j = startIndex; j > prevStartIndex; --j)
        {
            std::vector< Iterator >::iterator start = mainChain.begin();
            std::vector< Iterator >::iterator end = start + calculateSearchLength(i, mainChain);

            std::vector< Iterator >::iterator insertionLocation = findInsertionLocation(start, end, subChain[j]);
            mainChain.insert(insertionLocation, subChain[j]);
        }

        if (jacobsthalNumber >= static_cast< int >(subChain.size()))
        {
            break;
        }

        prevStartIndex = startIndex;
    }
}

/**
 * @brief Update numbers with merged main chain
 */
void VectorSorter::updateNumbers(std::vector< Iterator > &mainChain, int sizeOfSingleGroup)
{
    std::vector< int > tempNumbers;

    for (std::vector< Iterator >::iterator it = mainChain.begin(); it != mainChain.end(); ++it)
    {
        for (int i = 0; i < sizeOfSingleGroup; ++i)
        {
            tempNumbers.push_back(*(*it + i));
        }
    }

    for (int i = tempNumbers.size(); i != static_cast< int >(mNumbers.size()); ++i)
    {
        tempNumbers.push_back(mNumbers[i]);
    }

    mNumbers = tempNumbers;
}

/**
 * @brief Sort numbers using Ford-Johnson algorithm
 */
void VectorSorter::fordJohnsonSort(int sizeOfSingleGroup)
{
    // Return when only one group remains and there are no more groups to swap
    if (mNumbers.size() / sizeOfSingleGroup == 1)
    {
        return;
    }

    divideAndSwap(sizeOfSingleGroup);
    fordJohnsonSort(sizeOfSingleGroup * 2);

    std::vector< Iterator > mainChain, subChain;
    createMainAndSubChain(mainChain, subChain, sizeOfSingleGroup);

    mergeChains(mainChain, subChain);
    updateNumbers(mainChain, sizeOfSingleGroup);
}

/**
 * @brief Print sequence of numbers
 */
void VectorSorter::printVector(const std::string &label) const
{
    std::cout << label << ": ";
    if (label == "Before")
    {
        for (int i = 1; i < mArgc; ++i)
        {
            std::cout << mArgv[i] << " ";
        }
    }
    else
    {
        for (size_t i = 0; i < mNumbers.size(); ++i)
        {
            std::cout << mNumbers[i] << " ";
        }
    }
    std::cout << std::endl;
}

/**
 * @brief Check if the sorted numbers are in ascending order
 */
void VectorSorter::checkAscendingOrder() const
{
    for (size_t i = 0; i < mNumbers.size() - 1; ++i)
    {
        if (mNumbers[i] > mNumbers[i + 1])
        {
            std::cerr << "Error - The numbers are not in ascending order" << std::endl;
            return;
        }
    }
}