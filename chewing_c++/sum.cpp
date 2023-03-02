#include <iostream>

int	main(void) {
	int	sum = 0;

	for (int i = 1; i <= 10; i++) {
		sum += i;
	}
	std::cout << "합은 : " << sum << std::endl;
	return 0;
}
