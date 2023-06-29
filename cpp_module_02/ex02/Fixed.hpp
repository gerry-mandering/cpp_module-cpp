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

typedef int fixed_point_t;

class Fixed {
private:
    fixed_point_t mNumber;

    static const int mFractionalBitCount = 8;

public:
    Fixed();

    Fixed(const int number);

    Fixed(const float number);

    ~Fixed();

    Fixed(const Fixed &fixed);

    Fixed &operator=(const Fixed &fixed);

    bool operator>(const Fixed &fixed) const;

    bool operator<(const Fixed &fixed) const;

    bool operator>=(const Fixed &fixed);

    bool operator<=(const Fixed &fixed);

    bool operator==(const Fixed &fixed);

    bool operator!=(const Fixed &fixed);

    Fixed operator+(const Fixed &fixed);

    Fixed operator-(const Fixed &fixed);

    Fixed operator*(const Fixed &fixed);

    Fixed operator/(const Fixed &fixed);

    Fixed &operator++();

    Fixed operator++(fixed_point_t);

    Fixed &operator--();

    Fixed operator--(fixed_point_t);

//    friend std::ostream &operator<<(std::ostream &output, const Fixed &fixed); ㅇㅣ런 식의 동작은 됐지만 왜 되는지

    int getRawBits(void) const;

    void setRawBits(int const raw);

    float toFloat(void) const;

    int toInt(void) const;

    static Fixed &min(Fixed &fixedA, Fixed &fixedB);

    static const Fixed &min(const Fixed &fixedA, const Fixed &fixedB);

    static Fixed &max(Fixed &fixedA, Fixed &fixedB);

    static const Fixed &max(const Fixed &fixedA, const Fixed &fixedB);
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif
