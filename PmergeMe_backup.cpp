#include "PmergeMe.hpp"

const int PmergeMe::jacobsthal[PmergeMe::ARRAY_SIZE] = {
    1,       3,        5,        11,       21,       43,        85,        171,       341,       683,     1365,
    2731,    5461,     10923,    21845,    43691,    87381,     174763,    349525,    699051,    1398101, 2796203,
    5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};

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

PmergeMe::PmergeMe(int argc, char **argv) : mArgc(argc), mArgv(argv)
{
    const int tempArray[] = {2, 24, 12, 32, 11, 6, 1, 41, 123, 23, 12, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    mNumbers.insert(mNumbers.begin(), tempArray, tempArray + sizeof(tempArray) / sizeof(tempArray[0]));

    // for (int i = 0; i < 3000; i++)
    // {
    //     numbers.push_back(rand() % 10000);
    // }
}

void PmergeMe::run()
{
    // validation

    // parse arguments

    std::cout << "<Init>" << std::endl;
    printVector();
    std::cout << std::endl;

    fordJohnsonSort(1);
}

void PmergeMe::printVector() const
{
    std::vector< int >::const_iterator it;

    std::cout << "numbers : { ";
    for (it = mNumbers.begin(); it != mNumbers.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << std::endl;
}

void PmergeMe::swapGroup(Iterator front, Iterator back, int groupSize)
{
    for (int i = 0; i < groupSize; i++)
    {
        std::iter_swap(front + i, back + i);
    }
}

std::vector< PmergeMe::Iterator >::iterator PmergeMe::binaryInsertion(std::vector< Iterator >::iterator start,
                                                                      std::vector< Iterator >::iterator end,
                                                                      Iterator target)
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

void PmergeMe::fordJohnsonSort(int groupSize)
{
    if (mNumbers.size() / groupSize == 1)
    {
        return;
    }

    // Division
    Iterator front = mNumbers.begin();
    Iterator back = front + groupSize;
    while (true)
    {
        if (*front < *back)
        {
            swapGroup(front, back, groupSize);
        }

        int leftDistance = std::distance(back, mNumbers.end());
        if (leftDistance < groupSize)
        {
            break;
        }

        front = back + groupSize;
        back = front + groupSize;
    }

    printVector();
    fordJohnsonSort(groupSize * 2);

    // Main, Pending 분리
    std::vector< Iterator > mainVec, pendVec;
    Iterator mainElement = mNumbers.begin();
    Iterator pendElement = mainElement + groupSize;
    while (true)
    {
        mainVec.push_back(mainElement);
        pendVec.push_back(pendElement);

        int leftDistance = std::distance(pendElement + groupSize, mNumbers.end());
        if (leftDistance < groupSize * 2) // Odd도 Pending에 같이 들어감
        {
            if (leftDistance >= groupSize)
            {
                pendVec.push_back(pendElement + groupSize);
            }
            break;
        }
        else if (leftDistance < groupSize)
        {
            break;
        }

        mainElement = pendElement + groupSize;
        pendElement = mainElement + groupSize;
    }

    int prevIndex, jacobsthalNumber;

    prevIndex = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        jacobsthalNumber = jacobsthal[i];

        if (jacobsthalNumber > pendVec.size())
        {
            for (int j = pendVec.size() - 1; j >= prevIndex; j--)
            {
                Iterator selectedPendElement = pendVec[j];

                std::vector< Iterator >::iterator start = mainVec.begin();

                int searchWidth = std::pow(2, i + 1) - 1;
                if (searchWidth > mainVec.size())
                {
                    searchWidth = mainVec.size();
                }

                std::vector< Iterator >::iterator end = start + searchWidth;
                std::vector< Iterator >::iterator loc = binaryInsertion(start, end, selectedPendElement);

                mainVec.insert(loc, selectedPendElement);
            }
            break;
        }

        for (int j = jacobsthalNumber - 1; j >= prevIndex; j--)
        {
            Iterator selectedPendElement = pendVec[j];

            std::vector< Iterator >::iterator start = mainVec.begin();

            int searchWidth = std::pow(2, i + 1) - 1;
            if (searchWidth > mainVec.size())
            {
                searchWidth = mainVec.size();
            }

            std::vector< Iterator >::iterator end = start + searchWidth;
            std::vector< Iterator >::iterator loc = binaryInsertion(start, end, selectedPendElement);

            mainVec.insert(loc, selectedPendElement);
        }
        prevIndex = jacobsthalNumber; // prevIndex 명칭 바꾸기

        if (jacobsthalNumber == pendVec.size())
        {
            break;
        }
    }

    std::vector< int > newV;
    for (auto it = mainVec.begin(); it != mainVec.end(); it++)
    {
        for (int i = 0; i < groupSize; i++)
        {
            newV.push_back(*(*it + i));
        }
    }

    if (newV.size() != mNumbers.size())
    {
        for (int i = newV.size(); i != mNumbers.size(); i++)
        {
            newV.push_back(mNumbers[i]);
        }
    }

    mNumbers = newV;

    printVector();
}
