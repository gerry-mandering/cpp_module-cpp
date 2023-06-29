/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:28:23 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:28:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;

    this->mNumber = 0;
}

Fixed::Fixed(const int number) {
    std::cout << "Int constructor called" << std::endl;

    this->mNumber = roundf(number * (1 << this->mFractionalBitCount));
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;

    this->mNumber = roundf(number * (1 << this->mFractionalBitCount));
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;

    *this = fixed;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &fixed)
        this->mNumber = fixed.getRawBits();

    return *this;
}

//연산자 오버로딩 왜 Fixed:: 없는지
std::ostream &operator<<(std::ostream &output, const Fixed &fixed) {
    output << fixed.toFloat();

    return output;
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
