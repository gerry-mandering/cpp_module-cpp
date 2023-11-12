#include "StringTrimmer.hpp"
#include "TypeDeterminer.hpp"
#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [input]" << std::endl;
        return (1);
    }

    std::string input = argv[1];
    StringTrimmer::trim(input);

    ScalarType type = TypeDeterminer::determineType(input);

    if (type == CHAR) {
        std::cout << "Determined Type : char" << std::endl;
    }
    else if (type == INT) {
        std::cout << "Determined Type : int" << std::endl;
    }
    else if (type == FLOAT) {
        std::cout << "Determined Type : float" << std::endl;
    }
    else if (type == DOUBLE) {
        std::cout << "Determined Type : double" << std::endl;
    }
    else {
        std::cout << "Determined Type : invalid" << std::endl;
    }

    std::cout << std::endl;

    ScalarConverter::convert(input);

    return (0);
}