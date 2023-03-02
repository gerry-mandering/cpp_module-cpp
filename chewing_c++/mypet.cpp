#include <iostream>

typedef struct Animal {
	char	name[30];
	int		age;
	int		health;
	int		food;
	int		clean;
}	Animal;

void	create_animal(Animal* animal) {
	std::cout << "Name? :";
	std::cin >> animal->name;

	std::cout << "Age? :";
	std::cin >>animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void	play(Animal* animal) {
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void	one_day_pass(Animal* animal) {
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void	show_stat(Animal* animal) {
	std::cout << animal->name << "'s Status" << std::endl;
	std::cout << "Health : " << animal->health << std::endl;
	std::cout << "Food : " << animal->food << std::endl;
	std::cout << "Clean : " << animal->clean << std::endl;
}

int	main(void) {
	Animal* list[30];
	int		animal_number = 0;
	int		input;
	int		play_with;

	while (true) {
		std::cout << "1. Add Animal" << std::endl;
		std::cout << "2. Play" << std::endl;
		std::cout << "3. See Status" << std::endl;

		std::cin >> input;

		switch (input) {
			case 1:
				list[animal_number] = new Animal;
				create_animal(list[animal_number]);
				animal_number++;
				break;
			case 2:
				std::cout << "play with who? : ";
				std::cin >> play_with;

				if (play_with < animal_number)
					play(list[play_with]);
				break;
			case 3:
				std::cout << "check who? : ";
				std::cin >> play_with;
				if (play_with < animal_number)
					show_stat(list[play_with]);
				break;
		}
		for (int i = 0; i < animal_number; i++) {
			one_day_pass(list[i]);
		}
	}
	for (int i = 0; i < animal_number; i++) {
		delete list[i];
	}
	return 0;
}
