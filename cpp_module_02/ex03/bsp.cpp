/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:29:34 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:29:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Vector.hpp"

// Function Declaration
Sign signOfCrossProduct(const Vector &vector1, const Vector &vector2);

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Vector vectorAB(a, b);
    Vector vectorAX(a, point);

    Vector vectorBC(b, c);
    Vector vectorBX(b, point);

    Vector vectorCA(c, a);
    Vector vectorCX(c, point);

    if (signOfCrossProduct(vectorAB, vectorAX) == signOfCrossProduct(vectorBC, vectorBX) &&
        signOfCrossProduct(vectorAB, vectorAX) == signOfCrossProduct(vectorCA, vectorCX))
        return true;
    return false;
}

Sign signOfCrossProduct(const Vector &vector1, const Vector &vector2) {
    Fixed crossProductMagnitude = vector1.getCrossProductMagnitude(vector2);

    if (crossProductMagnitude.getRawBits() & SIGN_MASK)
        return NEGATIVE;
    return POSITIVE;
}
