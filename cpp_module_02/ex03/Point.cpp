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

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &point) {
    *this = point;
}

Point::~Point() {
//    std::cout << "Destructor called" << std::endl;
}

Point &Point::operator=(const Point &point) {
    if (this != &point) {
        this->~Point();
        new (this) Point(point);
    }

    return *this;
}
