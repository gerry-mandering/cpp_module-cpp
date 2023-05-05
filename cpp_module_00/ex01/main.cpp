#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phoneBook;
	std::string	input_command;

	while (true) {
		std::cout << "Please Enter Command: ";
		std::cin >> input_command;

		if (std::cin.eof() == true)
			break;

		if (input_command == "EXIT")
			return 0;
		else if (input_command == "ADD")
			phoneBook.Add();
		else if (input_command == "SEARCH")
			phoneBook.Search();
		else
			std::cout << "Wrong Command! Please Enter Again!";

		std::cout << std::endl;
	}

	return 0;
}
