#include "Span.hpp"
#include <iostream>

int main()
{
    try
    {
        // Test default constructor
        Span defaultSpan;
        std::cout << "Default constructor test passed." << std::endl;

        // Test parameterized constructor
        Span paramSpan(10);
        std::cout << "Parameterized constructor test passed." << std::endl;

        // Test copy constructor and assignment
        Span original(5);
        original.addNumber(1);
        Span copy = original;
        Span assigned(3);
        assigned = original;
        std::cout << "Copy constructor and assignment operator test passed." << std::endl;

        // Test addNumber and ContainerFullException
        Span fullSpan(2);
        fullSpan.addNumber(1);
        fullSpan.addNumber(2);
        try
        {
            fullSpan.addNumber(3);
            std::cout << "ContainerFullException test failed." << std::endl;
        }
        catch (const Span::ContainerFullException &)
        {
            std::cout << "ContainerFullException test passed." << std::endl;
        }

        // Test shortestSpan and longestSpan
        Span spanForTesting(5);
        spanForTesting.addNumber(1);
        spanForTesting.addNumber(3);
        spanForTesting.addNumber(6);
        spanForTesting.addNumber(11);
        spanForTesting.addNumber(18);
        if (spanForTesting.shortestSpan() == 2 && spanForTesting.longestSpan() == 17)
        {
            std::cout << "shortestSpan and longestSpan test passed." << std::endl;
        }
        else
        {
            std::cout << "shortestSpan and longestSpan test failed." << std::endl;
        }

        // Test NotEnoughElementsException
        Span smallSpan(1);
        smallSpan.addNumber(1);
        try
        {
            smallSpan.shortestSpan();
            std::cout << "NotEnoughElementsException test failed." << std::endl;
        }
        catch (const Span::NotEnoughElementsException &)
        {
            std::cout << "NotEnoughElementsException test passed." << std::endl;
        }

        // Test iterator methods
        Span iterSpan(2);
        iterSpan.addNumber(5);
        iterSpan.addNumber(10);
        if (*iterSpan.begin() == 5 && *(--iterSpan.end()) == 10)
        {
            std::cout << "Iterator methods test passed." << std::endl;
        }
        else
        {
            std::cout << "Iterator methods test failed." << std::endl;
        }

        Span spanForInsert(5);
        std::vector< int > numbersToInsert;
        numbersToInsert.push_back(1);
        numbersToInsert.push_back(2);
        numbersToInsert.push_back(3);
        spanForInsert.insert(spanForInsert.begin(), numbersToInsert.begin(), numbersToInsert.end());
        std::cout << "Insert method test passed." << std::endl;

        // Test insert method for ContainerFullException
        Span fullSpanForInsert(3);
        fullSpanForInsert.insert(fullSpanForInsert.begin(), numbersToInsert.begin(), numbersToInsert.end());
        try
        {
            std::vector< int > moreNumbers;
            moreNumbers.push_back(4);
            moreNumbers.push_back(5);
            fullSpanForInsert.insert(fullSpanForInsert.end(), moreNumbers.begin(), moreNumbers.end());
            std::cout << "ContainerFullException on insert test failed." << std::endl;
        }
        catch (const Span::ContainerFullException &)
        {
            std::cout << "ContainerFullException on insert test passed." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
