#include "PhoneBook.hpp"

void execute_command(const std::string &command, PhoneBook &phoneBook, bool &exit_flag);

int main(void) {
    PhoneBook phonebook;
    std::string command;
    bool exit_flag = false;

    while (!exit_flag) {
        std::cout << "Please enter the command: ";

        reenter:
        std::cin >> command;

        if (std::cin.eof()) {
            std::cout << "\nEOF condition has been encountered!\n\n";
            std::cin.clear();
            clearerr(stdin);
            std::cout << "Please reenter the command: ";
            goto reenter;
        }

        execute_command(command, phonebook, exit_flag);
    }
    return 0;
}

void execute_command(const std::string &command, PhoneBook &phonebook, bool &exit_flag) {
    if (command == "EXIT")
        exit_flag = true;
    else if (command == "ADD")
        phonebook.Add();
    else if (command == "SEARCH")
        phonebook.Search();
    else
        std::cout << "Wrong Command! Please Enter Again!\n\n";
}
