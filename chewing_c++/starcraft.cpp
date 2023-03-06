#include <iostream>
#include <string.h>

class	Marin {
	private:
		int		hp;
		int		coord_x, coord_y;
		int		damage;
		bool	is_dead;
		char*	name;

	public:
		Marin();
		Marin(int x, int y);
		Marin(int x, int y, const char* marin_name);
		~Marin();

		int		attack();
		void	be_attacked(int damage_earn);
		void	move(int x, int y);

		void	show_status();
};

Marin::Marin() {
	this->hp = 50;
	this->coord_x = 0;
	this->coord_y = 0;
	damage = 5;
	is_dead = false;
	name = nullptr;
}

Marin::Marin(int x, int y) {
	this->hp = 50;
	this->coord_x = x;
	this->coord_y = y;
	this->damage = 5;
	this->is_dead = false;
	this->name = nullptr;
}

Marin::Marin(int x, int y, const char* marin_name) {
	this->hp = 50;
	this->coord_x = x;
	this->coord_y = y;
	this->damage = 5;
	this->is_dead = false;
	this->name = new char[std::strlen(marin_name) + 1];
	strcpy(name, marin_name);
}

int	Marin::attack() {
	return this->damage;
}

void	Marin::move(int x, int y) {
	this->coord_x = x;
	this->coord_y = y;
}

void	Marin::be_attacked(int damage_earn) {
	this->hp -= damage_earn;
	if (this->hp < 0)
		this->is_dead = true;
}

void	Marin::show_status() {
	std::cout << " *** Marin : " << name << "***" << std::endl;
	std::cout << " Location : (" << this->coord_x << ", " << this->coord_y << ")" << std::endl;
	std::cout << " HP : " << this->hp << std::endl;
}

Marin::~Marin() {
	std::cout << name << "'s Destructor Called!" << std::endl;
	if (this->name != nullptr)
		delete[] name;
}

int	main(void) {
//	Marin	marin1(2, 3);
//	Marin	marin2(3, 5);
//
//	marin1.show_status();
//	marin2.show_status();
//
//	std::cout << std::endl << "Marin1 Attacked Marin2!!" << std::endl;
//	marin2.be_attacked(marin1.attack());
//
//	marin1.show_status();
//	marin2.show_status();

	Marin*	marines[100];

	marines[0] = new Marin(2, 3, "Marin 2");
	marines[1] = new Marin(3, 5, "Marin 1");

	marines[0]->show_status();
	marines[1]->show_status();

	std::cout << std::endl << "Marin1 Attacked Marin2!!" << std::endl;

	marines[0]->be_attacked(marines[1]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];

	return 0;
}
