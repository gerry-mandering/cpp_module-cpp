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

Harl::Harl() {}

const std::string &Harl::getLevel() const {
    return mLevel;
}

void Harl::printInstruction() const {
    std::cout << "Available Levels : { DEBUG, INFO, WARNING, ERROR }" << std::endl;
}

void clearEof() {
    std::cout << "\nEOF condition has been encountered!\n";
    std::cin.clear();
    clearerr(stdin);
}

bool isLevelValid(const std::string &level) {
    std::string validLevels[4] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR",
    };

    for (int i = 0; i < 4; i++) {
        if (level == validLevels[i])
            return true;
    }

    return false;
}

void Harl::receiveInput() {
    GET_INPUT:
    std::cout << "Please enter the level : " << std::endl;
    std::getline(std::cin, mLevel);

    if (std::cin.eof()) {
        clearEof();
        goto GET_INPUT;
    }

    if (!isLevelValid(mLevel)) {
        std::cout << "Invalid Input" << std::endl;
        goto GET_INPUT;
    }
}

Level getCorrespondingEnum(const std::string &level) {
    std::string levels[4] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR",
    };

    int i;
    for (i = 0; i < 4; i++) {
        if (level == levels[i])
            break;
    }

    return static_cast<Level>(i);
}

void Harl::complain(std::string level) {
    LevelFunction levelFunctions[4] = {
            &Harl::debug,
            &Harl::info,
            &Harl::warning,
            &Harl::error,
    };
    Level eLevel = getCorrespondingEnum(level);

    (this->*levelFunctions[static_cast<int>(eLevel)])();
}

void Harl::debug(void) {
    std::cout
            << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
            << "I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout
            << "I cannot believe adding extra bacon costs more money." << std::endl
            << "You didn’t put enough bacon in my burger!" << std::endl
            << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout
            << "I think I deserve to have some extra bacon for free." << std::endl
            << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout
            << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
