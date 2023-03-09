#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phonebook;
	std::string	input_command;

	do {
		std::cin >> input_command;

		if (input_command == "ADD")
			phonebook.Add();
		else if (input_command == "SEARCH")
			phonebook.Search();

		input_command.clear();
	} while (input_command == "EXIT");

	return 0;
}
