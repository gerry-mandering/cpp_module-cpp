#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    srand(time(NULL));

    // Testing default test
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shoud be 2: ";
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << "Shoud be 14: ";
    std::cout << sp.longestSpan() << std::endl;

    // Testing addNumber and ContainerFullException
    Span fullSpan = Span(2);
    fullSpan.addNumber(1);
    fullSpan.addNumber(2);

    std::cout << "Should throw exception: ";
    try
    {
        fullSpan.addNumber(3);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Testing shortestSpan and longestSpan
    Span randomSpan = Span(10000);
    for (int i = 0; i < 10000; i++)
    {
        randomSpan.addNumber(rand());
    }

    std::cout << "Should find shortestSpan: ";
    std::cout << randomSpan.shortestSpan() << std::endl;
    std::cout << "Should find longestSpan: ";
    std::cout << randomSpan.longestSpan() << std::endl;

    // Testing NotEnoughElementsException
    Span smallSpan = Span(1);
    smallSpan.addNumber(1);

    std::cout << "Should throw exception: ";
    try
    {
        smallSpan.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Testing fill
    std::vector< int > tempVector;
    tempVector.push_back(1);
    tempVector.push_back(2);
    tempVector.push_back(3);
    tempVector.push_back(4);

    Span sp1(4);
    sp1.addNumber(sp1.begin(), tempVector.begin(), tempVector.end());

    std::cout << "Should be 1, 2, 3, 4: " << std::endl;
    for (Span::iterator iter = sp1.begin(); iter != sp1.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << std::endl;

    // Testing fill with ContainerFullException
    Span fullSpan2(3);

    std::cout << "Should throw exception: ";
    try
    {
        fullSpan2.addNumber(fullSpan2.begin(), tempVector.begin(), tempVector.end());
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Testing fill with const_iterator
    int tempArray[] = {10, 20, 30, 40};
    const std::vector< int > constTempVector(tempArray, tempArray + sizeof(tempArray) / sizeof(tempArray[0]));

    Span sp2(4);
    sp2.addNumber(sp2.begin(), constTempVector.begin(), constTempVector.end());

    std::cout << "Should be 10, 20, 30, 40: " << std::endl;
    for (Span::iterator iter = sp2.begin(); iter != sp2.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    // Testing const_iterator
    const Span sp3(4);
    Span::const_iterator constIter = sp3.begin();
    (void)constIter;

    return 0;
}
