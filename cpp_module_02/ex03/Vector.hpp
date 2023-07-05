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

#include "Point.hpp"

class Vector {
public:
    ~Vector();
    Vector(const Vector &vector);
    Vector &operator=(const Vector &vector);

public:
    Vector(const Point tail, const Point head);

public:
    Fixed crossProduct(const Vector &vector) const;

private:
    Fixed x;
    Fixed y;

private:
    Vector();
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif