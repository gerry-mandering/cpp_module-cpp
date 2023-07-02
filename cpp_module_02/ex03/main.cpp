/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:30:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/01 16:30:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"

// Fuction Declaration
bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void) {

    Point a(1, 1);
    Point b(3, 5);
    Point c(4, 2);
    Point point(3, 3);

    if (bsp(a, b, c, point))
        std::cout << "point is inside the triangle" << std::endl;
    else
        std::cout << "point is outside the triangle" << std::endl;

    return 0;
}