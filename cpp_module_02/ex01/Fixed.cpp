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

    mRaw = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;

    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &fixed)
        mRaw = fixed.getRawBits();

    return *this;
}

Fixed::Fixed(const int number) {
    std::cout << "Int constructor called" << std::endl;

    mRaw = roundf(number * (1 << Fixed::FRACTIONAL_BIT_COUNT));
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;

    mRaw = roundf(number * (1 << Fixed::FRACTIONAL_BIT_COUNT));
}

int Fixed::getRawBits(void) const {
    return mRaw;
}

void Fixed::setRawBits(int const raw) {
    mRaw = raw;
}

float Fixed::toFloat(void) const {
    return mRaw / (float) (1 << Fixed::FRACTIONAL_BIT_COUNT);
}

int Fixed::toInt(void) const {
    return mRaw / (1 << Fixed::FRACTIONAL_BIT_COUNT);
}

//연산자 오버로딩 왜 Fixed:: 없는지
std::ostream &operator<<(std::ostream &output, const Fixed &fixed) {
    output << fixed.toFloat();

    return output;
}
