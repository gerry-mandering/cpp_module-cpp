#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		void	SetFirstName(const std::string& first_name);
		void	SetLastName(const std::string& last_name);
		void	SetNickname(const std::string& nickname);
		void	SetPhoneNumber(const std::string& phone_number);
		void	SetDarkestSecret(const std::string& darkest_secret);

		const std::string&	GetFirstName();
		const std::string&	GetLastName();
		const std::string&	GetNickname();
		const std::string&	GetPhoneNumber();
		const std::string&	GetDarkestSecret();
};

class PhoneBook {
	private:
		Contact	contact_array[8];
		int		current_index;

	public:
		PhoneBook();

		void	Add();
		void	Search();
};

#endif
