/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:28:41 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:28:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
//    std::cout << "Default constructor called" << std::endl;

    this->mNumber = 0;
}

Fixed::Fixed(const int number) {
//    std::cout << "Int constructor called" << std::endl;

    this->mNumber = roundf(number * (1 << this->mFractionalBitCount));
}

Fixed::Fixed(const float number) {
//    std::cout << "Float constructor called" << std::endl;

    this->mNumber = roundf(number * (1 << this->mFractionalBitCount));
}

Fixed::~Fixed() {
//    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
//    std::cout << "Copy constructor called" << std::endl;

    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
//    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &fixed)
        this->mNumber = fixed.getRawBits();

    return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
    return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(const Fixed &fixed) const {
    return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(const Fixed &fixed) {
    return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(const Fixed &fixed) {
    return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(const Fixed &fixed) {
    return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed &fixed) {
    return this->toFloat() != fixed.toFloat();
}

Fixed Fixed::operator+(const Fixed &fixed) {
    Fixed temp(this->getRawBits() + fixed.getRawBits());

    return temp;
}

Fixed Fixed::operator-(const Fixed &fixed) {
    Fixed temp(this->getRawBits() - fixed.getRawBits());

    return temp;
}

Fixed Fixed::operator*(const Fixed &fixed) {
    Fixed temp(this->getRawBits() * fixed.getRawBits() / (float) (1 << 16));

    return temp;

}

Fixed Fixed::operator/(const Fixed &fixed) {
    Fixed temp(this->getRawBits() / fixed.getRawBits());

    return temp;
}

Fixed &Fixed::operator++() {
    ++(this->mNumber);

    return *this;
}

Fixed Fixed::operator++(fixed_point_t) {
    Fixed temp(*this);

    ++(this->mNumber);

    return temp;
}

Fixed &Fixed::operator--() {
    --(this->mNumber);

    return *this;
}

Fixed Fixed::operator--(fixed_point_t) {
    Fixed temp(this->getRawBits());

    --(temp.mNumber);

    return temp;
}

int Fixed::getRawBits(void) const {
    return this->mNumber;
}

void Fixed::setRawBits(int const raw) {
    this->mNumber = raw;
}

float Fixed::toFloat(void) const {
    return (this->mNumber / (float) (1 << this->mFractionalBitCount));
}

int Fixed::toInt(void) const {
    return (this->mNumber / (1 << this->mFractionalBitCount));
}

Fixed &Fixed::min(Fixed &fixedA, Fixed &fixedB) {
    return fixedA < fixedB ? fixedA : fixedB;
}

const Fixed &Fixed::min(const Fixed &fixedA, const Fixed &fixedB) {
    return fixedA < fixedB ? fixedA : fixedB;
}

Fixed &Fixed::max(Fixed &fixedA, Fixed &fixedB) {
    return fixedA > fixedB ? fixedA : fixedB;
}

const Fixed &Fixed::max(const Fixed &fixedA, const Fixed &fixedB) {
    return fixedA > fixedB ? fixedA : fixedB;
}

//연산자 오버로딩 왜 Fixed:: 없는지
std::ostream &operator<<(std::ostream &output, const Fixed &fixed) {
    output << fixed.toFloat();

    return output;
}
