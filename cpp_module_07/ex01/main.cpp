#include "iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "intArray: ";
    ::iter(intArray, intArrayLength, ::printElement<int>);
    std::cout << std::endl;

    std::string strArray[] = {"Hi!", "I'm", "minseok2"};
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "strArray: ";
    ::iter(strArray, strArrayLength, ::printElement<std::string>);
    std::cout << std::endl;

    return 0;
}