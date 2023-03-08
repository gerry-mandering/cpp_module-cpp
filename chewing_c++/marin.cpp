#include <iostream>

class	Marine {
	private:
		int			hp;
		int			coord_x, coord_y;
		bool		is_dead;
		const int	damage;
		static int	total_marine_number;

	public:
		Marine();
		Marine(int x, int y);
		Marine(int x, int y, int damage);

		int		attack() const;
		Marine&	be_attacked(int damage_earn);
		void	move(int x, int y);

		void	show_status();
		static void	show_total_marine();
		~Marine();
};

int	Marine::total_marine_number = 0;

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {
	std::cout << "Constructer Called!!" << std::endl;
	this->total_marine_number++;
}

Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false) {
	std::cout << "Constructer Called!!" << std::endl;
	this->total_marine_number++;
}

Marine::Marine(int x, int y, int damage) : hp(50), coord_x(x), coord_y(y), damage(damage), is_dead(false) {
	std::cout << "Constructer Called!!" << std::endl;
	this->total_marine_number++;
}

int	Marine::attack() const {
	return this->damage;
}

Marine&	Marine::be_attacked(int damage_earn) {
	this->hp -= damage_earn;
	if (this->hp <= 0)
		this->is_dead = true;

	return *this;
}

void	Marine::move(int x, int y) {
	this->coord_x = x;
	this->coord_y = y;
}

void	Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : (" << this->coord_x << ", " << this->coord_y << ")" << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " Current total number of marines : " << this->total_marine_number << std::endl;
}

void	Marine::show_total_marine() {
	std::cout << "Total Marine Count : " << total_marine_number << std::endl;
}

Marine::~Marine() {
	this->total_marine_number--;
}

void	create_marine() {
	Marine	marine3(10, 10, 4);

	marine3.show_status();
}

int	main(void) {
	Marine	marine1(2, 3, 10);
	Marine	marine2(3, 5, 10);

	marine1.show_status();
	marine2.show_status();
	Marine::show_total_marine();

	create_marine();

	std::cout << std::endl << "Marine1 attacked Marine2!!" << std::endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

	return 0;
}
