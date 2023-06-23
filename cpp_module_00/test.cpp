//
// Created by Minseok Kim on 6/20/23.
//
#include <unistd.h>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string command;

    for (int i = 0; i < 10; i++) {
        std::cout << "Please enter the command: ";

        if (!std::getline(std::cin, command)) {
            if (std::cin.eof()) {
                int a = 0;

                std::cout << "\nEOF condition has been encountered!\n\n";
                std::cin.clear();
                scanf("%d", &a);
                printf("%d\n", a);
                continue;
            } else {
                std::cerr << "Error reading command\n";
                return 1;  // Return with error code
            }
        }

        // Add command processing code here
    }

    return 0;
}