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
//    const int tempArray[] = {2, 24, 12, 32, 11, 6, 1, 41, 123, 23, 12, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//    v.insert(v.begin(), tempArray, tempArray + sizeof(tempArray) / sizeof(tempArray[0]));

    for (int i = 0; i < 3000; i++)
    {
        v.push_back(rand() % 10000);
    }
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

    std::cout << "v : { ";
    for (it = v.begin(); it != v.end(); it++)
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
    std::cout << "1" << std::endl;
    std::vector< Iterator >::iterator mid;
    while (start != end)
    {
        std::cout << "2" << std::endl;
        mid = start + std::distance(start, end) / 2;
        if (*(*mid) < *target)
        {
            std::cout << "3" << std::endl;
            start = mid + 1;
        }
        else
        {
            std::cout << "4" << std::endl;
            end = mid;
        }
    }
    std::cout << "5" << std::endl;
    return start;
}

void PmergeMe::fordJohnsonSort(int groupSize)
{
    std::cout << "---------------------------" << std::endl;
    std::cout << "GroupSize : " << groupSize << std::endl;

    if (v.size() / groupSize == 1)
    {
        return;
    }

    // Division
    Iterator front = v.begin();
    Iterator back = front + groupSize;
    while (true)
    {
        if (*front < *back)
        {
            swapGroup(front, back, groupSize);
        }

        int leftDistance = std::distance(back, v.end());
        if (leftDistance < groupSize)
        {
            break;
        }

        front = back + groupSize;
        back = front + groupSize;
    }

    printVector();
    fordJohnsonSort(groupSize * 2);

    std::cout << "---------------------------" << std::endl;
    std::cout << "GroupSize : " << groupSize << std::endl;

    // Main, Pending 분리
    std::vector< Iterator > mainVec, pendVec;
    Iterator mainElement = v.begin();
    Iterator pendElement = mainElement + groupSize;
    while (true)
    {
        std::cout << "mainElement : " << *mainElement << " pendingElement : " << *pendElement << std::endl;
        mainVec.push_back(mainElement);
        pendVec.push_back(pendElement);

        int leftDistance = std::distance(pendElement + groupSize, v.end());
        std::cout << "leftDistance : " << leftDistance << std::endl;
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

    std::cout << "mainVec : { ";
    for (auto it = mainVec.begin(); it != mainVec.end(); it++)
    {
        std::cout << *(*it) << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "pendVec : { ";
    for (auto it = pendVec.begin(); it != pendVec.end(); it++)
    {
        std::cout << *(*it) << " ";
    }
    std::cout << "}" << std::endl;

    int prevIndex, jacobsthalNumber;

    prevIndex = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << "i : " << i << std::endl;

        jacobsthalNumber = jacobsthal[i];
        std::cout << "jacobsthalNumber : " << jacobsthalNumber << std::endl;

        if (jacobsthalNumber > pendVec.size())
        {
            for (int j = pendVec.size() - 1; j >= prevIndex; j--)
            {
                Iterator selectedPendElement = pendVec[j];
                std::cout << "selectedPendElement : " << *selectedPendElement << std::endl;

                std::vector< Iterator >::iterator start = mainVec.begin();

                int searchWidth = std::pow(2, i + 1) - 1;
                if (searchWidth > mainVec.size())
                {
                    searchWidth = mainVec.size();
                }
                std::cout << "searchWidth : " << searchWidth << std::endl;

                std::vector< Iterator >::iterator end = start + searchWidth;

                std::vector< Iterator >::iterator loc = binaryInsertion(start, end, selectedPendElement);
                std::cout << "loc : " << *(*loc) << std::endl;

                mainVec.insert(loc, selectedPendElement);

                std::cout << "mainVec : { ";
                for (auto it = mainVec.begin(); it != mainVec.end(); it++)
                {
                    std::cout << *(*it) << " ";
                }
                std::cout << "}" << std::endl;
            }
            break;
        }

        for (int j = jacobsthalNumber - 1; j >= prevIndex; j--)
        {
            Iterator selectedPendElement = pendVec[j];
            std::cout << "selectedPendElement : " << *selectedPendElement << std::endl;

            std::vector< Iterator >::iterator start = mainVec.begin();

            int searchWidth = std::pow(2, i + 1) - 1;
            if (searchWidth > mainVec.size())
            {
                searchWidth = mainVec.size();
            }
            std::cout << "searchWidth : " << searchWidth << std::endl;

            std::vector< Iterator >::iterator end = start + searchWidth;

            if (end == mainVec.end())
            {
                std::cout << "end == mainVec.end()" << std::endl;
            }

            std::vector< Iterator >::iterator loc = binaryInsertion(start, end, selectedPendElement);
            if (loc == mainVec.end())
            {
                std::cout << "loc == mainVec.end()" << std::endl;
            }
            else
            {
                std::cout << "loc : " << *(*loc) << std::endl;
            }

            mainVec.insert(loc, selectedPendElement);
            std::cout << "mainVec : { ";
            for (auto it = mainVec.begin(); it != mainVec.end(); it++)
            {
                std::cout << *(*it) << " ";
            }
            std::cout << "}" << std::endl;
        }
        prevIndex = jacobsthalNumber; // prevIndex 명칭 바꾸기

        if (jacobsthalNumber == pendVec.size())
        {
            break;
        }
    }

    std::cout << "mainVec : { ";
    for (auto it = mainVec.begin(); it != mainVec.end(); it++)
    {
        std::cout << *(*it) << " ";
    }
    std::cout << "}" << std::endl;

    std::vector< int > newV;
    for (auto it = mainVec.begin(); it != mainVec.end(); it++)
    {
        for (int i = 0; i < groupSize; i++)
        {
            newV.push_back(*(*it + i));
        }
    }

    if (newV.size() != v.size())
    {
        for (int i = newV.size(); i != v.size(); i++)
        {
            newV.push_back(v[i]);
        }
    }

    v = newV;

    printVector();
}
