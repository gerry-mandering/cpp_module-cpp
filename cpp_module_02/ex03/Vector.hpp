/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/01 16:30:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include "Point.hpp"

class Vector {
private:
    Fixed x;
    Fixed y;

public:
    Vector();
    ~Vector();
    Vector(const Vector &vector);
    Vector &operator=(const Vector &vector);

public:
    Vector(const Point tail, const Point head);

public:
    Fixed crossProduct(const Vector &vector) const;
};

#endif