#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
//    if (argc < 2)
//    {
//        std::cerr << "Error" << std::endl;
//        return 1;
//    }

    PmergeMe pmergeMe(argc, argv);
    pmergeMe.run();

    return 0;
}