/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:28:41 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/26 18:28:41 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bitset>
#include "Fixed.hpp"

int main(void) {

    Fixed test(-1.25f);
    std::cout << std::bitset<32>(test.getRawBits()) << std::endl;

    Fixed test2(-2);
    std::cout << std::bitset<32>(test2.getRawBits()) << std::endl;

    Fixed a(3.125f);
    Fixed c(3.1415f);
    Fixed const b(Fixed(5.05f) / Fixed(2));

    std::cout << a << std::endl;
    std::cout << c << std::endl;
    std::cout << a + c << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}