/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:28:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/24 21:28:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
              << std::endl;
}

void Harl::info(void) {
    std::cout
            << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
            << std::endl;
}

void Harl::warning(void) {
    std::cout
            << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
            << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl() {
    this->commentFunctions[DEBUG] = &Harl::debug;
    this->commentFunctions[INFO] = &Harl::info;
    this->commentFunctions[WARNING] = &Harl::warning;
    this->commentFunctions[ERROR] = &Harl::error;
}

void Harl::complain(std::string level) {
    std::string levels[TotalComment] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < TotalComment; i++) {
        if (level == levels[i]) {
            (this->*commentFunctions[i])();
            return;
        }
    }

    std::cout << "Invalid Input" << std::endl;
}
