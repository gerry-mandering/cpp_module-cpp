/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:43 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {}

DiamondTrap::~DiamondTrap() {}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
    *this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
    if (this != &diamondTrap) {
        setName(diamondTrap.getName());
        setHitPoint(diamondTrap.getHitPoint());
        setEnergyPoint(diamondTrap.getEnergyPoint());
        setAttackDamage(diamondTrap.getAttackDamage());
    }

    return *this;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"),
                                                    FragTrap(name + "_clap_name") {
    mName = name;

    FragTrap::setHitPoint(100);
    ScavTrap::setEnergyPoint(50);
    FragTrap::setAttackDamage(30);
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        std::cout << "DiamondTrap " << getName() << " cannot take damage" << std::endl;
        return;
    }

    if (amount > getHitPoint())
        setHitPoint(0);
    else
        setHitPoint(getHitPoint() - amount);

    std::cout
            << "DiamondTrap " << getName() << " takes " << amount << " damage, "
            << getName() << "'s remaining Hit Point is " << getHitPoint()
            << std::endl;

}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        std::cout << "DiamondTrap " << getName() << " cannot be repaired" << std::endl;
        return;
    }

    setHitPoint(getHitPoint() + amount);
    setEnergyPoint(getEnergyPoint() - 1);

    std::cout
            << "DiamondTrap " << getName() << " repaired Hit Point worth about " << amount
            << ", " << getName() << "'s remaining Hit Point is " << getHitPoint()
            << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << mName << " and Also " << ClapTrap::getName() << std::endl;
}