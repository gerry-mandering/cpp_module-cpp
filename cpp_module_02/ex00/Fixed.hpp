/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:27:37 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:27:37 by minseok2         ###   ########.fr       */
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

    Fixed(const Fixed &fixed);

    ~Fixed();

    Fixed &operator=(const Fixed &fixed);

    int getRawBits(void) const;

    void setRawBits(int const raw);
};

#endif