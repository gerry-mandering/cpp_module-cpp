#include <iostream>

class Date {
	private:
		int	year;
		int	month;
		int	day;

	public:
		void	set_date(int year, int month, int date);
		void	add_day(int inc);
		void	add_month(int inc);
		void	add_year(int inc);

		int	get_current_month_total_days(int year, int month);

		void	show_date(void);
		Date(void) {
			this->year = 0;
			this->month = 0;
			this->day = 0;
		}
		Date(int year, int month, int date) {
			this->year = year;
			this->month = month;
			this->day = date;
		}
};

void	Date::set_date(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

int	Date::get_current_month_total_days(int year, int month) {
	static int	month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month != 2)
		return month_day[month - 1];
	else if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 29;
	else
		return 28;
}

void	Date::add_day(int inc) {
	int	current_month_total_days;

	while (true) {
		current_month_total_days = get_current_month_total_days(this->year, this->month);
		if (this->day + inc <= current_month_total_days) {
			this->day += inc;
			break;
		} else {
			inc -= (current_month_total_days - this->day + 1);
			this->day = 1;
			add_month(1);
		}
	}
}

void	Date::add_month(int inc) {
	add_year((inc + this->month - 1) / 12);
	this->month = this->month + inc % 12;
	this->month = (this->month == 12 ? 12 : this->month % 12);
}

void	Date::add_year(int inc) {
	this->year += inc;
}

void	Date::show_date(void) {
	std::cout << "Today : "
			  << this->year << " year "
			  << this->month << " month "
			  << this->day << "day" << std::endl;
}

int	main(void) {
	Date	day(2011, 3, 1);
	Date	day1;
	Date	day3;

	day.show_date();
	day1.show_date();
	day3.show_date();

	day.add_day(30);
	day.show_date();

	day.add_day(2000);
	day.show_date();

	day.set_date(2012, 1, 31);
	day.add_day(29);
	day.show_date();

	day.set_date(2012, 8, 4);
	day.add_day(2500);
	day.show_date();
	return 0;
}
