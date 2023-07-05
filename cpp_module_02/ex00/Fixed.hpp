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

class Fixed {
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    static const int FRACTIONAL_BIT_COUNT = 8;

    int mRaw;
};

#endif