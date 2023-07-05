/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/01 16:30:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector() {}

Vector::~Vector() {}

Vector::Vector(const Vector &vector) {
    *this = vector;
}

Vector &Vector::operator=(const Vector &vector) {
    if (this != &vector) {
        this->~Vector();
        new(this)Vector(vector);
    }

    return *this;
}

Vector::Vector(const Point tail, const Point head) {
    x = head.getX() - tail.getX();
    y = head.getY() - tail.getY();
}

Fixed Vector::crossProduct(const Vector &vector) const {
    Fixed result = (x * vector.y) - (y * vector.x);

    return result;
}
