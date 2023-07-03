/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:21 by minseok2         ###   ########.fr       */
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

const std::string &ClapTrap::getName() const {
    return mName;
}

const unsigned int &ClapTrap::getHitPoint() const {
    return mHitPoint;
}

const unsigned int &ClapTrap::getEnergyPoint() const {
    return mEnergyPoint;
}

const unsigned int &ClapTrap::getAttackDamage() const {
    return mAttackDamage;
}

void ClapTrap::setName(const std::string &name) {
    mName = name;
}

void ClapTrap::setHitPoint(const unsigned int &hitPoint) {
    mHitPoint = hitPoint;
}

void ClapTrap::setEnergyPoint(const unsigned int &energyPoint) {
    mEnergyPoint = energyPoint;
}

void ClapTrap::setAttackDamage(const unsigned int &attackDamage) {
    mAttackDamage = attackDamage;
}
