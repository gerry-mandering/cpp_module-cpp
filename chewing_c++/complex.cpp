#include <iostream>

class Complex {
	private:
		double	real, img;

	public:
		Complex(double real, double img) : real(real), img(img) {}
		Complex(const Complex& c) {
			this->real = c.real;
			this->img = c.img;
		}

		Complex	operator+(const Complex& c) const;
		Complex	operator-(const Complex& c) const;
		Complex	operator*(const Complex& c) const;
		Complex	operator/(const Complex& c) const;

		Complex&	operator=(const Complex& c);
		Complex&	operator+=(const Complex& c);
		Complex&	operator-=(const Complex& c);
		Complex&	operator*=(const Complex& c);
		Complex&	operator/=(const Complex& c);

		void	println() {
			std::cout << "( " << this->real << " , " << this->img << " )" << std::endl;
		}
};

Complex	Complex::operator+(const Complex &c) const {
	Complex	temp(this->real + c.real, this->img + c.img);

	return temp;
}

Complex	Complex::operator-(const Complex &c) const {
	Complex	temp(this->real - c.real, this->img - c.img);

	return temp;
}

Complex	Complex::operator*(const Complex &c) const {
	Complex	temp(this->real * c.real - this->img * c.img,
				 this->real * c.img + this->img * c.real);

	return temp;
}

Complex	Complex::operator/(const Complex &c) const {
	Complex	temp (
			(this->real * c.real + this->img * c.img) / (c.real * c.real + c.img * c.img),
			(this->img * c.real - this->real * c.img) / (c.real * c.real + c.img * c.img));

	return temp;
}

Complex&	Complex::operator=(const Complex &c) {
	this->real = c.real;
	this->img = c.img;

	return *this;
}

Complex&	Complex::operator+=(const Complex &c) {
	(*this) = (*this) + c;

	return *this;
}

Complex&	Complex::operator-=(const Complex &c) {
	(*this) = (*this) - c;

	return *this;
}

Complex&	Complex::operator*=(const Complex &c) {
	(*this) = (*this) * c;

	return *this;
}

Complex&	Complex::operator/=(const Complex &c) {
	(*this) = (*this) / c;

	return *this;
}

int	main(void) {
	Complex	a(1.0, 2.0);
	Complex	b(3.0, -2.0);
	Complex	c(0.0, 0.0);

	c = a * b + a / b + a + b;
	c.println();

	a += b;
	a.println();
	b.println();

	return 0;
}
