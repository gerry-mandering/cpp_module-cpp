/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:28:23 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:28:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

typedef int fixed_point_t;

class Fixed {
private:
    fixed_point_t mNumber;

    static const int mFractionalBitCount = 8;

public:
    Fixed();

    Fixed(const int number);

    Fixed(const float number);

    Fixed(const Fixed &fixed);

    ~Fixed();

    Fixed &operator=(const Fixed &fixed);

//    friend std::ostream &operator<<(std::ostream &output, const Fixed &fixed); ㅇㅣ런 식의 동작은 됐지만 왜 되는지

    int getRawBits(void) const;

    void setRawBits(int const raw);

    float toFloat(void) const;

    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif
