#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }

    RPN rpn(argv[1]);
    rpn.run();

    return 0;
}