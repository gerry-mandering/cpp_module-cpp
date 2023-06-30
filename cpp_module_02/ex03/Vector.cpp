/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:29:34 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:29:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector() {
    this->mVector = Point();
}

Vector::Vector(const Point tail, const Point head) {
    this->mVector = Point(head.x - tail.x, head.y - tail.y);
}

Vector::Vector(const Vector &vector) {
    *this = vector;
}

Vector::~Vector() {}

Vector &Vector::operator=(const Vector &vector) {
    if (this != &vector)
        this->mVector = vector.mVector;

    return *this;
}

Fixed Vector::getCrossProductMagnitude(const Vector &vector) const {
    Fixed crossProductMagnitude((this->mVector.x * vector.mVector.y)
                                - (this->mVector.y * vector.mVector.y));

    return crossProductMagnitude;
}
