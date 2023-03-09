#include <iostream>

void	print_default_msg(void) {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	print_uppercase_msg(int argc, char **argv) {
	int	string_length;

	for (int i = 1; i < argc; i++) {
		string_length = std::strlen(argv[i]);

		for (int j = 0; j < string_length; j++)
			std::cout << (char)std::toupper(argv[i][j]);
	}

	std::cout << std::endl;
}

int	main(int argc, char** argv) {
	if (argc == 1)
		print_default_msg();
	else
		print_uppercase_msg(argc, argv);

	return 0;
}
