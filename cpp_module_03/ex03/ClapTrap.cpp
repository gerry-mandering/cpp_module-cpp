/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:43 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    if (this != &clapTrap) {
        mName = clapTrap.getName();
        mHitPoint = clapTrap.getHitPoint();
        mEnergyPoint = clapTrap.getEnergyPoint();
        mAttackDamage = clapTrap.getAttackDamage();
    }

    return *this;
}

ClapTrap::ClapTrap(const std::string &name) :
        mName(name),
        mHitPoint(10),
        mEnergyPoint(10),
        mAttackDamage(0) {
    std::cout << "ClapTrap Constructor called" << std::endl;

    mMaxHitPoint = mHitPoint;
}

ClapTrap::ClapTrap(const std::string &name, const unsigned int hitPoint, const unsigned int energyPoint, const unsigned int attackDamage) :
        mName(name),
        mHitPoint(hitPoint),
        mEnergyPoint(energyPoint),
        mAttackDamage(attackDamage) {
    std::cout << "ClapTrap Constructor called" << std::endl;

    mMaxHitPoint = mHitPoint;
}

void ClapTrap::attack(const std::string &target) {
    if (!canOperate()) {
        printErrorMessage(ATTACK_FAIL);
        return;
    }

    useEnergy();

    std::cout << "ClapTrap " << mName << " attacks " << target
              << ", causing " << mAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!canOperate()) {
        printErrorMessage(TAKE_DAMAGE_FAIL);
        return;
    }

    if (amount > mHitPoint)
        mHitPoint = 0;
    else
        mHitPoint -= amount;

    std::cout << "ClapTrap " << mName << " takes " << amount << " damage, "
              << mName << "'s remaining Hit Point is " << mHitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!canOperate()) {
        printErrorMessage(BE_REPAIRED_FAIL);
        return;
    }

    if (mHitPoint + amount > mMaxHitPoint)
        amount = mMaxHitPoint - mHitPoint;
    mHitPoint += amount;
    useEnergy();

    std::cout << "ClapTrap " << mName << " repaired Hit Point worth about " << amount << ", "
              << mName << "'s remaining Hit Point is " << mHitPoint << std::endl;
}

const std::string &ClapTrap::getName() const { return mName; }

const unsigned int &ClapTrap::getHitPoint() const { return mHitPoint; }

const unsigned int &ClapTrap::getEnergyPoint() const { return mEnergyPoint; }

const unsigned int &ClapTrap::getAttackDamage() const { return mAttackDamage; }

void ClapTrap::setName(const std::string &name) { mName = name; }

void ClapTrap::setHitPoint(const unsigned int &hitPoint) { mHitPoint = hitPoint; }

void ClapTrap::setEnergyPoint(const unsigned int &energyPoint) { mEnergyPoint = energyPoint; }

void ClapTrap::setAttackDamage(const unsigned int &attackDamage) { mAttackDamage = attackDamage; }

bool ClapTrap::canOperate() const {
    if (mHitPoint == 0 || mEnergyPoint == 0)
        return false;
    return true;
}

void ClapTrap::useEnergy() {
    --mEnergyPoint;
}

void ClapTrap::printErrorMessage(eErrorMessage errorMessage) const {
    switch (errorMessage) {
        case ATTACK_FAIL:
            std::cout << "ClapTrap " << mName << " cannot attack" << std::endl;
            break;
        case TAKE_DAMAGE_FAIL:
            std::cout << "ClapTrap " << mName << " cannot take damage" << std::endl;
            break;
        case BE_REPAIRED_FAIL:
            std::cout << "ClapTrap " << mName << " cannot be repaired" << std::endl;
            break;
    }
}
