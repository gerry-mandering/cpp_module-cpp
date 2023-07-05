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

#include "Vector.hpp"

int main(void) {

    Point a(1, 1);
    Point b(1, 3);
    Point c(4, 2);
    Point point(2, 2);

    if (bsp(a, b, c, point))
        std::cout << "point is inside the triangle" << std::endl;
    else
        std::cout << "point is outside the triangle" << std::endl;

    return 0;
}