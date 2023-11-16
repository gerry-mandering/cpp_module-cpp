#include "functions.hpp"

Base *generate(void)
{
    int randomValue = rand() % 3;

    switch (randomValue)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }

    return NULL;
}

void identify(Base *p)
{
    A *aPtr = dynamic_cast< A * >(p);
    if (aPtr != NULL)
    {
        std::cout << "A" << std::endl;
        return;
    }

    B *bPtr = dynamic_cast< B * >(p);
    if (bPtr != NULL)
    {
        std::cout << "B" << std::endl;
        return;
    }

    C *cPtr = dynamic_cast< C * >(p);
    if (cPtr != NULL)
    {
        std::cout << "C" << std::endl;
        return;
    }

    std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &aRef = dynamic_cast< A & >(p);
        std::cout << "A" << std::endl;
        (void)aRef;
        return;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        B &bRef = dynamic_cast< B & >(p);
        std::cout << "B" << std::endl;
        (void)bRef;
        return;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        C &cRef = dynamic_cast< C & >(p);
        std::cout << "C" << std::endl;
        (void)cRef;
        return;
    }
    catch (const std::exception &e)
    {
    }

    std::cout << "Unknown" << std::endl;
}
