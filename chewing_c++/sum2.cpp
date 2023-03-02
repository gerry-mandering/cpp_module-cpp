#include <iostream>

int	main(void) {
	int	i, sum = 0;

	i = 1;
	while (i <= 10)
	{
		sum += i;
		i++;
	}
	std::cout << "합은 : " << sum << std::endl;
	return 0;
}
