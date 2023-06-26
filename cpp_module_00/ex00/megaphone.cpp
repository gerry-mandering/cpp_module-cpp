#include <iostream>

// ANSI Escape Code Color Define
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

// Function Declaration
void printUpperCaseMsg(int argc, char **argv);
void printDefaultMsg(void);

int main(int argc, char **argv) {
    if (argc == 1)
        printDefaultMsg();
    else
        printUpperCaseMsg(argc, argv);

    return 0;
}

void printDefaultMsg(void) {
    std::cout << RED "* LOUD AND UNBEARABLE FEEDBACK NOISE *" NC << std::endl;
}

void printUpperCaseMsg(int argc, char **argv) {
    int length;

    for (int i = 1; i < argc; i++) {
        std::string input(argv[i]);
        length = input.length();

        for (int j = 0; j < length; j++)
            std::cout << (char) std::toupper(argv[i][j]);
    }
    std::cout << std::endl;
}
