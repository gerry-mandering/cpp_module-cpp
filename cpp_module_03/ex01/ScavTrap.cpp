/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:59:52 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 19:59:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
    *this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    if (this != &scavTrap) {
        mName = scavTrap.mName;
        mHitPoint = scavTrap.mHitPoint;
        mEnergyPoint = scavTrap.mEnergyPoint;
        mAttackDamage = scavTrap.mAttackDamage;
    }

    return *this;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "ScavTrap Constructor called" << std::endl;

    mHitPoint = 100;
    mEnergyPoint = 50;
    mAttackDamage = 20;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << mName << " is now in Gate Keeper Mode!" << std::endl;
}