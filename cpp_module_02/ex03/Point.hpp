/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/01 16:30:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
public:
    Point();
    ~Point();
    Point(const Point &point);
    Point &operator=(const Point &point);

public:
    Point(const float x, const float y);

public:
    const Fixed &getX() const;
    const Fixed &getY() const;

private:
    const Fixed x;
    const Fixed y;

};

#endif