#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook() {

}

void	PhoneBook::Add() {
	Contact		newContact;
	std::string	input;
	std::string	item[5] = {"First Name", "Last Name", "Nick Name", "Phone Number", "Darkest Secret"};
	int	i = 0;

	void (Contact::*setter[5])(const std::string&) = {
        &Contact::setFirstName,
        &Contact::setLastName,
        &Contact::setNickname,
        &Contact::setPhoneNumber,
        &Contact::setDarkestSecret
    };

	for (int i = 0; i < 5; i++) {
		std::cout << "Please Enter Your " << item[i] << ": ";
		std::cin >> input;
		(newContact.*setter[i])(input);
		input.clear();
	}

	contact_array[this->current_index] = newContact;

	if (this->current_index == 8)
		this->current_index = 0;
	else
		this->current_index++;

	if (total_contact != 8)
		this->total_contact++;
}

void	PhoneBook::Search() {
	for (int i = 0; i < total_contact; i++) {
		std::cout.width(10);
		std::cout << contact_array[i].getFirstName() << "|";
		std::cout.width(10);
		std::cout << contact_array[i].getLastName() << "|";
		std::cout.width(10);
		std::cout << contact_array[i].getNickName() << "|";
		std::cout.width(10);
		std::cout << contact_array[i].getPhoneNumber() << "|";
		std::cout.width(10);
		std::cout << contact_array[i].getDarkestSecret() << std::endl;
	}
}
