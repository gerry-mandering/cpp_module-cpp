#include <iostream>

int main(void) {
    std::string input;

    while (1) {
        std::cin >> input;
        std::cout << "std::cin : " << std::cin << std::endl;
        if (std::cin.eof()) {
            std::cout << "EOF DETECTED" << std::endl;
            std::cin.clear();
            std::cout << "Changed std::cin : " << std::cin << std::endl;
            continue;
        }
        std::cout << input << std::endl;
    }
    return 0;
}