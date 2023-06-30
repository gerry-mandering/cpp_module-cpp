/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:29:34 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:29:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include "Point.hpp"

#define SIGN_MASK (1 << 31)

typedef enum sign {
    POSITIVE,
    NEGATIVE,
} Sign;

class Vector {
private:
    typedef Point Vector_t;

    Vector_t mVector;

public:
    Vector();

    Vector(const Point tail, const Point head);

    Vector(const Vector &vector);

    ~Vector();

    Vector &operator=(const Vector &vector);

    Fixed getCrossProductMagnitude(const Vector &vector) const;
};

#endif