#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
    // Testing with non-const vector
    std::vector< int > intVector;
    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);
    intVector.push_back(4);

    std::cout << "Should be 3: ";
    try
    {
        std::vector< int >::const_iterator iter = easyfind(intVector, 3);
        std::cout << *iter << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Should throw exception: ";
    try
    {
        std::vector< int >::const_iterator iter2 = easyfind(intVector, 5);
        std::cout << *iter2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Testing with const vector
    int tempArray[] = {10, 20, 30, 40};
    const std::vector< int > constIntVector(tempArray, tempArray + sizeof(tempArray)/ sizeof(tempArray[0]));

    std::cout << "Should be 20: ";
    try
    {
        std::vector< int >::const_iterator iter3 = easyfind(constIntVector, 20);
        std::cout << *iter3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Should throw exception: ";
    try
    {
        std::vector< int >::const_iterator iter4 = easyfind(constIntVector, 50);
        std::cout << *iter4 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Testing with non-const list
    std::list< int > intList;
    intList.push_back(100);
    intList.push_back(200);
    intList.push_back(300);
    intList.push_back(400);

    std::cout << "Should be 400: ";
    try
    {
        std::list< int >::const_iterator iter5 = easyfind(intList, 400);
        std::cout << *iter5 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}