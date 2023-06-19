#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

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
