/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/01 16:30:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
    static const int FRACTIONAL_BIT_COUNT = 8;
    static const int SIGN_MASK = (1 << 31);

private:
    int mRaw;

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

//    friend std::ostream &operator<<(std::ostream &output, const Fixed &fixed); ㅇㅣ런 식의 동작은 됐지만 왜 되는지
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

public:
    typedef enum sign {
        POSITIVE,
        NEGATIVE,
    } Sign;

    Sign sign() const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif
