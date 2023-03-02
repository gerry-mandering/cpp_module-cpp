#include <iostream>

int	main(void) {
	int	lucky_number = 13;
	int	input_number;

	std::cout << "Guess the Lucky Number" << std::endl;
	while (true) {
		std::cout << "Input Number : ";
		std::cin >> input_number;
		if (input_number == lucky_number) {
			std::cout << "Correct" << std::endl;
			break;
		} else {
			std::cout << "Wrong! Try Again" << std::endl;
		}
	}
	return 0;
}
