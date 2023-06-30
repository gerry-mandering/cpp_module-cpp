/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:29:34 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:29:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

// Function Declaration
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {

    Point const a(1, 1);
    Point const b(4, 2);
    Point const c(3, 5);
    Point const point(3, 3);

    bool bInsideTriangle;

    bInsideTriangle = bsp(a, b, c, point);

    if (bInsideTriangle)
        std::cout << "The point is inside the triangle" << std::endl;
    else
        std::cout << "The point is outside the triangle" << std::endl;

    return 0;
}