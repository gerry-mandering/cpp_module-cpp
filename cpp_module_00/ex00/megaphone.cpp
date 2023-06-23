#include <iostream>

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
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void printUpperCaseMsg(int argc, char **argv) {
    int length;

    for (int i = 1; i < argc; i++) {
        length = std::strlen(argv[i]);

        for (int j = 0; j < length; j++)
            std::cout << (char) std::toupper(argv[i][j]);
    }
    std::cout << std::endl;
}
