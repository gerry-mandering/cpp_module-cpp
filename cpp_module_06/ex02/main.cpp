#include "functions.hpp"
#include <time.h>

int main(void)
{
    srand(time(NULL));

    Base *aPtr = new A();
    std::cout << "aPtr: ";
    identify(aPtr);

    Base *randomPtr = generate();
    std::cout << "randomPtr: ";
    identify(randomPtr);

    C cInstance;
    Base &cRef = cInstance;
    std::cout << "cRef: ";
    identify(cRef);

    Base *randomPtr2 = generate();
    std::cout << "randomPtr2: ";
    identify(*randomPtr2);

    delete aPtr;
    delete randomPtr;
    delete randomPtr2;

    return 0;
}