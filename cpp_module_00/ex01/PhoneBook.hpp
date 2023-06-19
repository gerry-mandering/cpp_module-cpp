#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
    Contact mContacts[8];
    int mCurrentIndex;
    int mTotalContact;

    void newContact(Contact &contact);

    void printPhoneBook();

    std::string conformForm(const std::string &input);

    void printContact(int &index);

public:
    PhoneBook();

    void Add();

    void Search();
};

#endif
