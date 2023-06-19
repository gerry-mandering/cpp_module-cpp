#include "PhoneBook.hpp"
#include "Contact.hpp"

#define FIELD_SIZE 5

PhoneBook::PhoneBook() {
    this->mCurrentIndex = 0;
    this->mTotalContact = 0;
}

void PhoneBook::newContact(Contact &contact) {
    std::string input;
    std::string fields[FIELD_SIZE] = {
            "First Name",
            "Last Name",
            "Nick Name",
            "Phone Number",
            "Darkest Secret",
    };
    int i = 0;

    while (i < FIELD_SIZE) {
        std::cout << fields[i] << ":\n";
        getline(std::cin, input);

        if (std::cin.eof()) {
            std::cout << "\nEOF condition has been encountered!\n";
            std::cin.clear();
            clearerr(stdin);
            continue;
        }

        (contact.*(contact.Setters[i++]))(input);
    }
}

void PhoneBook::Add() {
    Contact contact;

    newContact(contact);

    mContacts[this->mCurrentIndex++] = contact;

    if (this->mCurrentIndex == 8)
        this->mCurrentIndex = 0;
    if (mTotalContact != 8)
        this->mTotalContact++;
}

std::string PhoneBook::conformForm(const std::string &input) {
    if (input.size() <= 10)
        return input;
    return input.substr(0, 9) + ".";
}

void PhoneBook::printPhoneBook() {
    for (int i = 0; i < mTotalContact; i++) {
        std::cout.width(10);
        std::cout << i << "|";
        std::cout.width(10);
        std::cout << conformForm(mContacts[i].GetFirstName()) << "|";
        std::cout.width(10);
        std::cout << conformForm(mContacts[i].GetLastName()) << "|";
        std::cout.width(10);
        std::cout << conformForm(mContacts[i].GetNickName()) << std::endl;
    }
}

void PhoneBook::printContact(int &index) {
    std::cout << "First Name: " << mContacts[index].GetFirstName() + "\n";
    std::cout << "Last Name: " << mContacts[index].GetLastName() + "\n";
    std::cout << "Nick Name: " << mContacts[index].GetNickName() + "\n";
    std::cout << "Phone Number: " << mContacts[index].GetPhoneNumber() + "\n";
    std::cout << "Darkest Secret: " << mContacts[index].GetDarkestSecret() + "\n";
}

void PhoneBook::Search() {
    int index;

    if (mTotalContact == 0) {
        std::cout << "PhoneBook is Empty!\n";
        return;
    }

    printPhoneBook();

    REENTER:
    std::cout << "Please enter the index:\n";
    std::cin >> index;

    if (std::cin.eof()) {
        std::cout << "\nEOF condition has been encountered!\n";
        std::cin.clear();
        clearerr(stdin);
        goto REENTER;
    } else if (std::cin.fail()) {
        std::cout << "Wrong type was entered!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto REENTER;
    } else if (index < 0 || index > mTotalContact - 1) {
        std::cout << "Index is out of range!\n";
        goto REENTER;
    }

    std::cin.ignore();

    printContact(index);
}