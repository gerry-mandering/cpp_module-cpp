#include <iostream>

int	main(void) {
	int	arr[3] = {1, 2, 3};
	int	(&ref)[3] = arr;

	for (int i = 0; i < 3; i++) {
		std::cout << arr[i] << std::endl;
		std::cout << ref[i] << std::endl;
	}

	ref[0] = 4;
	ref[1] = 5;
	ref[2] = 6;

	for (int i = 0; i < 3; i++) {
		std::cout << arr[i] << std::endl;
		std::cout << ref[i] << std::endl;
	}
	return 0;
}
