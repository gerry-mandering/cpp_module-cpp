#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contact_array[8];
		int		current_index;
		int		total_contact;

	public:
		PhoneBook();

		void	Add();
		void	Search();
};

#endif
