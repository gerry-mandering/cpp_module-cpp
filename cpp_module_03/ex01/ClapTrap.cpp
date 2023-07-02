/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:59:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 19:59:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    if (this != &clapTrap) {
        mName = clapTrap.mName;
        mHitPoint = clapTrap.mHitPoint;
        mEnergyPoint = clapTrap.mEnergyPoint;
        mAttackDamage = clapTrap.mAttackDamage;
    }

    return *this;
}

ClapTrap::ClapTrap(const std::string &name) {
    std::cout << "ClapTrap Constructor called" << std::endl;

    mName = name;
    mHitPoint = 10;
    mEnergyPoint = 10;
    mAttackDamage = 0;
}

void ClapTrap::attack(const std::string &target) {
    if (mHitPoint == 0 || mEnergyPoint == 0) {
        std::cout << "ClapTrap " << mName << " cannot attack" << std::endl;
        return;
    }

    std::cout
            << "ClapTrap " << mName << " attacks " << target
            << ", causing " << mAttackDamage << " points of damage!"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (mHitPoint == 0 || mEnergyPoint == 0) {
        std::cout << "ClapTrap " << mName << " cannot take damage" << std::endl;
        return;
    }

    if (amount > mHitPoint)
        mHitPoint = 0;
    else
        mHitPoint -= amount;

    --mEnergyPoint;

    std::cout
            << "ClapTrap " << mName << " takes " << amount << " damage, "
            << mName << "'s remaining Hit Point is " << mHitPoint
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (mHitPoint == 0 || mEnergyPoint == 0) {
        std::cout << "ClapTrap " << mName << " cannot be repaired" << std::endl;
        return;
    }

    mHitPoint += amount;
    --mEnergyPoint;

    std::cout
            << "ClapTrap " << mName << " repaired Hit Point worth about " << amount
            << ", " << mName << "'s remaining Hit Point is " << mHitPoint
            << std::endl;
}
