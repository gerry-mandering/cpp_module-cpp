/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:48:06 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/25 13:48:06 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout
            << "[DEBUG]" << std::endl
            << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
            << "I really do!" << std::endl
            << std::endl;
}

void Harl::info(void) {
    std::cout
            << "[INFO]" << std::endl
            << "I cannot believe adding extra bacon costs more money." << std::endl
            << "You didn’t put enough bacon in my burger!" << std::endl
            << "If you did, I wouldn’t be asking for more!" << std::endl
            << std::endl;
}

void Harl::warning(void) {
    std::cout
            << "[WARNING]" << std::endl
            << "I think I deserve to have some extra bacon for free." << std::endl
            << "I’ve been coming for years whereas you started working here since last month." << std::endl
            << std::endl;
}

void Harl::error(void) {
    std::cout
            << "[ERROR]" << std::endl
            << "This is unacceptable! I want to speak to the manager now." << std::endl
            << std::endl;
}

Harl::Harl() {
    this->commentFunctions[DEBUG] = &Harl::debug;
    this->commentFunctions[INFO] = &Harl::info;
    this->commentFunctions[WARNING] = &Harl::warning;
    this->commentFunctions[ERROR] = &Harl::error;
}

bool Harl::getCommentType(const std::string &level, CommentType &commentType) const {
    std::string levels[TotalComment] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < TotalComment; i++) {
        if (level == levels[i]) {
            commentType = (CommentType) i;
            return true;
        }
    }

    return false;
}

void Harl::complain(std::string level) {
    CommentType commentType;

    if (!getCommentType(level, commentType)) {
        std::cout << "Invalid Input" << std::endl;
        return;
    }

    switch (commentType) {
        case DEBUG:
            (this->*commentFunctions[DEBUG])();
        case INFO:
            (this->*commentFunctions[INFO])();
        case WARNING:
            (this->*commentFunctions[WARNING])();
        case ERROR:
            (this->*commentFunctions[ERROR])();
    }
}
