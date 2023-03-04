#include <iostream>

class	Animal {
	private:
		int	food;
		int	weight;
	
	public:
		void	set_animal(int food, int weight) {
			this->food = food;
			this->weight = weight;
		}
		void	increase_food(int inc) {
			this->food += inc;
			this->weight += (inc / 3);
		}
		void	view_stat(void) {
			std::cout << "이 동물의 food : " << this->food << std::endl;
			std::cout << "이 동물의 weight : " << this->weight << std::endl;
		}
};

int	main(void) {
	Animal	animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}
