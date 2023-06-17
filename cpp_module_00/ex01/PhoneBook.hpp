#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int current_index;
    int total_contact;

    void print_phonebook();
    void print_contact();

public:
    PhoneBook();

    void Add();

    void Search();
};

#endif
