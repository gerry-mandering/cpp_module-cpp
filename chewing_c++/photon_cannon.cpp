#include <cstring>
#include <iostream>
#include <string.h>

class	Photon_Cannon {
	private:
		int		hp, shield;
		int		coord_x, coord_y;
		int		damage;
		char*	name;

	public:
		Photon_Cannon(int x, int y);
		Photon_Cannon(const Photon_Cannon& photon_cannon);
		Photon_Cannon(int x, int y, const char* cannon_name);
		~Photon_Cannon();

		void	show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "Constructor Called!" << std::endl;
	this->hp = 100;
	this->shield = 100;
	this->coord_x = x;
	this->coord_y = y;
	this->damage = 20;
	this->name = nullptr;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
	std::cout << "Constructor Called!" << std::endl;
	this->hp = 100;
	this->shield = 100;
	this->coord_x = x;
	this->coord_y = y;
	this->damage = 20;
	this->name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& photon_cannon) {
	std::cout << "Copy Constructor Called!" << std::endl;
	this->hp = photon_cannon.hp;
	this->shield = photon_cannon.shield;
	this->coord_x = photon_cannon.coord_x;
	this->coord_y = photon_cannon.coord_y;
	this->damage = photon_cannon.damage;
	this->name = new char[strlen(photon_cannon.name) + 1];
	strcpy(this->name, photon_cannon.name);
}

void	Photon_Cannon::show_status() {
	std::cout << "Photon_Cannon " << this->name << std::endl;
	std::cout << " Location : (" << this->coord_x << ", " << this->coord_y << ")" << std::endl;
	std::cout << " HP : " << this->hp << std::endl;
}

Photon_Cannon::~Photon_Cannon() {
	std::cout << "Destructor Called!" << std::endl;
	if (name != nullptr)
		delete [] this->name;
}

int	main() {
	Photon_Cannon	pc1(3, 3, "Cannon");
	Photon_Cannon	pc2 = pc1;

	pc1.show_status();
	pc2.show_status();

	return 0;
}
