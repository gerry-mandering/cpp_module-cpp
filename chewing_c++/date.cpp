#include <iostream>

class Date {
	private:
		int	year;
		int	month;
		int	day;

	public:
		void	set_date(int year, int month, int date) {
			this->year = year;
			this->month = month;
			this->day = date;
		}
		void	add_day(int inc) {
			int	day_arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

			while (inc > 0) {
				if ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0)
					day_arr[1] = 29;
				else
					day_arr[1] = 28;

				if (this->day + inc > day_arr[this->month - 1]) {
					inc -= day_arr[this->month - 1] - this->day + 1;
					add_month(1);
					this->day = 1;
				} else {
					this->day += inc;
					break;
				}
			}
		}
		void	add_month(int inc) {
			while (inc > 0) {
				if (this->month + inc > 12) {
					inc -= 12 - this->month + 1;
					add_year(1);
					this->month = 1;
				} else {
					this->month += inc;
					break;
				}
			}
		}
		void	add_year(int inc) {
			this->year += inc;
		}
		void	show_date(void) {
			std::cout << this->year << " year "
					  << this->month << " month "
					  << this->day << " day" << std::endl;
		}
};

int	main(void) {
	Date	date;

	date.set_date(2023, 3, 3);
	date.show_date();
	date.add_day(3000);
	date.show_date();
	date.add_month(15);
	date.show_date();
	date.add_year(10);
	date.show_date();
}
