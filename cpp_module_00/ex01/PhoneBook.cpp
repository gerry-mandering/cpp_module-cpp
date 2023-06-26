#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
    this->mCurrentIndex = 0;
    this->mTotalContact = 0;
}

void PhoneBook::Add() {
    Contact contact;

    newContact(contact);

    mContacts[this->mCurrentIndex++] = contact;

    if (this->mCurrentIndex == 8)
        this->mCurrentIndex = 0;
    if (mTotalContact < 8)
        this->mTotalContact++;
}

void PhoneBook::Search() const {
    int index;

    if (mTotalContact == 0) {
        std::cout << RED "PhoneBook is Empty!\n" NC << std::endl;
        return;
    }

    printPhoneBook();

    REENTER:
    std::cout << "Please enter the index: " << std::endl;
    std::cin >> index;

    if (std::cin.eof()) {
        std::cout << RED "\nEOF condition has been encountered!\n" NC << std::endl;
        std::cin.clear();
        clearerr(stdin);
        goto REENTER;
    } else if (std::cin.fail()) {
        std::cout << RED "Wrong type was entered!\n" NC << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto REENTER;
    } else if (index < 0 || index > mTotalContact - 1) {
        std::cout << RED "Index is out of range!\n" NC << std::endl;
        goto REENTER;
    }

    std::cin.ignore();

    printContact(index);
}

void PhoneBook::newContact(Contact &contact) const {
    std::string fields[FIELD_SIZE] = {
            "First Name",
            "Last Name",
            "Nick Name",
            "Phone Number",
            "Darkest Secret",
    };
    std::string input;
    int i = 0;

    while (i < FIELD_SIZE) {
        std::cout << fields[i] << ": " << std::endl;
        std::getline(std::cin, input);

        if (std::cin.eof()) {
            std::cout << RED "\nEOF condition has been encountered!\n" NC << std::endl;
            std::cin.clear();
            clearerr(stdin);
            continue;
        }

        (contact.*(contact.setters[i++]))(input);
    }
    std::cout << std::endl;
}

std::string PhoneBook::conformForm(const std::string &input) const {
    if (input.size() <= 10)
        return input;
    return input.substr(0, 9) + ".";
}

void PhoneBook::printPhoneBook() const {
    std::cout << std::endl;
    for (int i = 0; i < mTotalContact; i++) {
        std::cout.width(10);
        std::cout << i << "|";
        std::cout.width(10);
        std::cout << conformForm(mContacts[i].getFirstName()) << "|";
        std::cout.width(10);
        std::cout << conformForm(mContacts[i].getLastName()) << "|";
        std::cout.width(10);
        std::cout << conformForm(mContacts[i].getNickName()) << std::endl;
        std::cout << std::endl;
    }
}

void PhoneBook::printContact(int &index) const {
    std::cout
            << std::endl
            << "First Name: " << mContacts[index].getFirstName() << std::endl
            << "Last Name: " << mContacts[index].getLastName() << std::endl
            << "Nick Name: " << mContacts[index].getNickName() << std::endl
            << "Phone Number: " << mContacts[index].getPhoneNumber() << std::endl
            << "Darkest Secret: " << mContacts[index].getDarkestSecret() << std::endl
            << std::endl;
}
