/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/01 16:30:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
//    std::cout << "Default constructor called" << std::endl;
    mRaw = 0;
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
        mRaw = fixed.mRaw;

    return *this;
}

Fixed::Fixed(const int number) {
//    std::cout << "Int constructor called" << std::endl;

    mRaw = number << Fixed::FRACTIONAL_BIT_COUNT;
}

Fixed::Fixed(const float number) {
//    std::cout << "Float constructor called" << std::endl;

    mRaw = roundf(number * (1 << Fixed::FRACTIONAL_BIT_COUNT));
}

bool Fixed::operator>(const Fixed &fixed) const {
    return mRaw > fixed.mRaw;
}

bool Fixed::operator<(const Fixed &fixed) const {
    return mRaw < fixed.mRaw;
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return mRaw >= fixed.mRaw;
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return mRaw <= fixed.mRaw;
}

bool Fixed::operator==(const Fixed &fixed) const {
    return mRaw == fixed.mRaw;
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return mRaw != fixed.mRaw;
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    int sum = mRaw + fixed.mRaw;

    Fixed result;
    result.setRawBits(sum);

    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    int diff = mRaw - fixed.mRaw;

    Fixed result;
    result.setRawBits(diff);

    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    int product = (mRaw * fixed.mRaw) >> Fixed::FRACTIONAL_BIT_COUNT;

    Fixed result;
    result.setRawBits(product);

    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    int quotient = (mRaw << Fixed::FRACTIONAL_BIT_COUNT) / fixed.mRaw;

    Fixed result;
    result.setRawBits(quotient);

    return result;
}

Fixed &Fixed::operator++() {
    ++mRaw;

    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);

    ++mRaw;

    return temp;
}

Fixed &Fixed::operator--() {
    --mRaw;

    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);

    --mRaw;

    return temp;
}

int Fixed::getRawBits(void) const {
    return mRaw;
}

void Fixed::setRawBits(int const raw) {
    mRaw = raw;
}

float Fixed::toFloat(void) const {
    return (float) mRaw / (1 << Fixed::FRACTIONAL_BIT_COUNT);
}

int Fixed::toInt(void) const {
    return mRaw / (1 << Fixed::FRACTIONAL_BIT_COUNT);
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

Fixed::Sign Fixed::sign() const {
    if (mRaw & Fixed::SIGN_MASK)
        return NEGATIVE;
    return POSITIVE;
}

//연산자 오버로딩 왜 Fixed:: 없는지
std::ostream &operator<<(std::ostream &output, const Fixed &fixed) {
    output << fixed.toFloat();

    return output;
}
