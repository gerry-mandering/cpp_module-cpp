#include <iostream>

int	main(void) {
	int	input_number;

	std::cout << "Print User Info" << std::endl;
	std::cout << "1. Name " << std::endl;
	std::cout << "2. Age " << std::endl;
	std::cout << "3. Gender " << std::endl;

	std::cin >> input_number;

	switch (input_number) {
		case 1:
			std::cout << "Minseok2" << std::endl;
			break;
		case 2:
			std::cout << "25" << std::endl;
			break;
		case 3:
			std::cout << "Man" << std::endl;
			break;
		default:
			std::cout << "Wrong Argument!" << std::endl;
			break;
	}
	return 0;
}
