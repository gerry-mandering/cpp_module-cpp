#include "Array.hpp"
#include <iostream>

int main()
{
    Array< int > intArray;
    std::cout << "Default constructed int array size: " << intArray.size() << std::endl;
    std::cout << std::endl;

    Array< double > doubleArray(5);
    std::cout << "Double array size (should be 5): " << doubleArray.size() << std::endl;

    for (unsigned int i = 0; i < doubleArray.size(); ++i)
    {
        doubleArray[i] = i * 1.5;
        std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
    }
    std::cout << std::endl;

    Array< double > copiedArray = doubleArray;
    std::cout << "Copied array size (should be 5): " << copiedArray.size() << std::endl;
    for (unsigned int i = 0; i < copiedArray.size(); ++i)
    {
        std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
    }
    std::cout << std::endl;

    Array< double > assignedArray;
    assignedArray = doubleArray;
    std::cout << "Assigned array size (should be 5): " << assignedArray.size() << std::endl;
    for (unsigned int i = 0; i < assignedArray.size(); ++i)
    {
        std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << "Trying to access out-of-range element..." << std::endl;
        doubleArray[10] = 3.14;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    Array< std::string > strArray(3);
    strArray[0] = "Hi!";
    strArray[1] = "I'm";
    strArray[2] = "minseok2";
    for (unsigned int i = 0; i < strArray.size(); ++i)
    {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }

    return 0;
}
