/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:28:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/24 21:28:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

// Function Declaration
void printInstruction(void);

int main(void) {
    Harl harl;
    std::string level;

    while (true) {
        printInstruction();
        std::cout << "Please enter the level: " << std::endl;
        getline(std::cin, level);

        if (std::cin.eof()) {
            std::cout << "\nEOF condition has been encountered!\n";
            std::cin.clear();
            clearerr(stdin);
            continue;
        }

        if (level == "EXIT")
            break;

        harl.complain(level);
    }

    return 0;
}

void printInstruction(void) {
    std::cout << "  <LEVEL>  " << std::endl;
    std::cout << "-  DEBUG  -" << std::endl;
    std::cout << "-  INFO   -" << std::endl;
    std::cout << "- WARNING -" << std::endl;
    std::cout << "-  ERROR  -" << std::endl;
    std::cout << "Do You Want To Exit? enter \"Exit\"" << std::endl;
}
