#include "PhoneBook.hpp"

// Function Declaration
void executeCommand(const std::string &command, PhoneBook &phoneBook);

int main(void) {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Please enter the command:\n";
        getline(std::cin, command);

        if (std::cin.eof()) {
            std::cout << "\nEOF condition has been encountered!\n";
            std::cin.clear();
            clearerr(stdin);
            continue;
        }

        if (command == "EXIT")
            break;

        executeCommand(command, phoneBook);
    }
    return 0;
}

void executeCommand(const std::string &command, PhoneBook &phoneBook) {
    if (command == "ADD")
        phoneBook.Add();
    else if (command == "SEARCH")
        phoneBook.Search();
    else
        std::cout << "Wrong Command! Please Enter Again!\n";
}
