#include <iostream>
#include <string.h>

class	Test {
	private:
		char	c;

	public:
		Test(char c) {
			this->c = c;
			std::cout << "Constructor Called!" << this->c << std::endl;
		}
		~Test() {
			std::cout << "Destructor Called!" << this->c << std::endl;
		}
};

void	simple_function() {
	Test	b('b');
}

int	main(void) {
	Test	a('a');

	simple_function();

	return 0;
}
