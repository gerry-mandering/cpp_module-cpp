#include <iostream>

class	A {
	private:
		mutable int	data;

	public:
		A(int data) : data(data) {}
		void	DoSomething(int x) const {
			this->data = x;
		}

		void	PrintData() const {
			std::cout << "data : " << this->data << std::endl;
		}
};

int	main(void) {
	A	a(10);

	a.DoSomething(3);
	a.PrintData();

	return 0;
}
