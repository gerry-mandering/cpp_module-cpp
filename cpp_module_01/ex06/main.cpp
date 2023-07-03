/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:48:06 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/25 13:48:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
        std::cout << "Invalid Input" << std::endl;
        return 0;
    }

    std::string level(argv[1]);
    harl.complain(level);

    return 0;
}
