#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <limits>

#define FIELD_SIZE 5

PhoneBook::PhoneBook() {
    this->current_index = 0;
    this->total_contact = 0;
}

void get_new_contact(Contact &new_contact) {
    std::string input;
    std::string fields[FIELD_SIZE] = {
            "First Name",
            "Last Name",
            "Nick Name",
            "Phone Number",
            "Darkest Secret",
    };

    for (int i = 0; i < FIELD_SIZE; i++) {
        std::cout << fields[i] << ": ";

        reenter:
        std::cin >> input;

        if (std::cin.eof()) {
            std::cout << "\nEOF condition has been encountered!" << std::endl;
            std::cin.clear();
            clearerr(stdin);
            std::cout << "Reenter " << fields[i] << ": ";
            goto reenter;
        }

        (new_contact.*(new_contact.setters[i]))(input);
    }
    std::cout << std::endl;
}

void PhoneBook::Add() {
    Contact new_contact;

    get_new_contact(new_contact);

    contacts[this->current_index++] = new_contact;

    if (this->current_index == 8)
        this->current_index = 0;
    if (total_contact != 8)
        this->total_contact++;
}

void PhoneBook::print_phonebook() {
    for (int i = 0; i < total_contact; i++) {
        std::cout.width(10);
        std::cout << i << "|";
        std::cout.width(10);
        std::cout << contacts[i].getFirstName() << "|";
        std::cout.width(10);
        std::cout << contacts[i].getLastName() << "|";
        std::cout.width(10);
        std::cout << contacts[i].getNickName() << "|";
    }
}

void PhoneBook::print_contact(int &index) {

}

void PhoneBook::Search() {
    int index;

    if (total_contact == 0) {
        std::cout << "PhoneBook is Empty!\n\n";
        return;
    }

    print_phonebook();

    std::cout << "Please enter the index: ";

    reenter:
    std::cin >> index;

    if (std::cin.eof()) {
        std::cout << "\nEOF condition has been encountered!" << std::endl;
        std::cin.clear();
        clearerr(stdin);
        std::cout << "Reenter " << fields[i] << ": ";
        goto reenter;
    } else if (std::cin.fail()) {
        std::cout << "\nWrong input was entered!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Reenter " << fields[i] << ": ";
        goto reenter;
    } else if (index < 0 || index > total_contact - 1) {
        std::cout << "\nIndex is out of range!" << std::endl;
        std::cout << "Reenter " << fields[i] << ": ";
        goto reenter;
    }

    print_contact(index);
}