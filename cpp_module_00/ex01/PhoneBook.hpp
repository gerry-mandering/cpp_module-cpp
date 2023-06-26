#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <cstdio>

// ANSI Escape Code Color Define
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

// Field Size Define
#define FIELD_SIZE 5

class PhoneBook {
private:
    Contact mContacts[8];
    int mCurrentIndex;
    int mTotalContact;

    void newContact(Contact &contact) const;
    void printPhoneBook() const;
    std::string conformForm(const std::string &input) const;
    void printContact(int &index) const;

public:
    PhoneBook();

    void Add();
    void Search() const;
};

#endif
