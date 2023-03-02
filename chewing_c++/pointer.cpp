#include <iostream>

void	change_val(int *number)
{
	*number = 3;
}

int	main(void) {
	int	number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
	return 0;
}
