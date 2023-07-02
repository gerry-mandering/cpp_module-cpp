/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/01 16:30:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
//    std::cout << "Default constructor called" << std::endl;
}

Point::~Point() {
//    std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point &point) : x(point.getX()), y(point.getY()){
//    std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &point) {
//    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &point) {
        this->~Point();
        new (this) Point(point);
    }

    return *this;
}

Point::Point(const float x, const float y) : x(x), y(y) {}

const Fixed &Point::getX() const {
    return x;
}

const Fixed &Point::getY() const {
    return y;
}
