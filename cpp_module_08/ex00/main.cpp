#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    std::vector< int > v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    try
    {
        std::vector< int >::const_iterator iter = easyfind(v1, 3);
        std::cout << *iter << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}