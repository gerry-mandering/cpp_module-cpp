/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:29:34 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:29:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {
    this->x = Fixed(0);
    this->y = Fixed(0);
}

Point::Point(const float x, const float y) {
    this->x = Fixed(x);
    this->y = Fixed(y);
}

Point::Point(const Point &point) {
    *this = point;
}

Point::~Point() {
//    std::cout << "Destructor called" << std::endl;
}

Point &Point::operator=(const Point &point) {
    if (this != &point) {
        this->x = point.x;
        this->y = point.y;
    }

    return *this;
}
