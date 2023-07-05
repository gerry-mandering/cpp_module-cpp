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

ScavTrap::ScavTrap() {}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
    *this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    if (this != &scavTrap) {
        setName(scavTrap.getName());
        setHitPoint(scavTrap.getHitPoint());
        setEnergyPoint(scavTrap.getEnergyPoint());
        setAttackDamage(scavTrap.getAttackDamage());
    }

    return *this;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "ScavTrap Constructor called" << std::endl;

    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
}

void ScavTrap::attack(const std::string &target) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        std::cout << "ScavTrap " << getName() << " cannot attack" << std::endl;
        return;
    }

    setEnergyPoint(getEnergyPoint() - 1);

    std::cout
            << "ScavTrap " << getName() << " attacks " << target
            << ", causing " << getAttackDamage() << " points of damage!"
            << std::endl;
}

/////////////////FIXXXXXXXXXXXXXXXXXX!!!!!
void ScavTrap::takeDamage(unsigned int amount) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        std::cout << "ScavTrap " << getName() << " cannot take damage" << std::endl;
        return;
    }

    if (amount > getHitPoint())
        setHitPoint(0);
    else
        setHitPoint(getHitPoint() - amount);

    std::cout
            << "ScavTrap " << getName() << " takes " << amount << " damage, "
            << getName() << "'s remaining Hit Point is " << getHitPoint()
            << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        std::cout << "ScavTrap " << getName() << " cannot be repaired" << std::endl;
        return;
    }

    setHitPoint(getHitPoint() + amount);
    setEnergyPoint(getEnergyPoint() - 1);

    std::cout
            << "ScavTrap " << getName() << " repaired Hit Point worth about " << amount
            << ", " << getName() << "'s remaining Hit Point is " << getHitPoint()
            << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate Keeper Mode!" << std::endl;
}
