/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/01 16:30:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point) {
    Vector vectorAB(a, b);
    Vector vectorAX(a, point);

    Fixed crossProductAbAx = vectorAB.crossProduct(vectorAX);

    Vector vectorBC(b, c);
    Vector vectorBX(b, point);

    Fixed crossProductBcBx = vectorBC.crossProduct(vectorBX);

    Vector vectorCA(c, a);
    Vector vectorCX(c, point);

    Fixed crossProductCaCx = vectorCA.crossProduct(vectorCX);

    if (crossProductAbAx.sign() == crossProductBcBx.sign() &&
        crossProductAbAx.sign() == crossProductCaCx.sign())
        return true;
    return false;
}
