/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:28:41 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:28:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);

    Fixed(const int number);
    Fixed(const float number);

public:
    bool operator>(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;

    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

public:
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

public:
    static Fixed &min(Fixed &fixedA, Fixed &fixedB);
    static const Fixed &min(const Fixed &fixedA, const Fixed &fixedB);
    static Fixed &max(Fixed &fixedA, Fixed &fixedB);
    static const Fixed &max(const Fixed &fixedA, const Fixed &fixedB);

private:
    static const int FRACTIONAL_BIT_COUNT = 8;

    int mRaw;
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif
