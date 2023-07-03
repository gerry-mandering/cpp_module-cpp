/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:43 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
    *this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    if (this != &fragTrap) {
        setName(fragTrap.getName());
        setHitPoint(fragTrap.getHitPoint());
        setEnergyPoint(fragTrap.getEnergyPoint());
        setAttackDamage(fragTrap.getAttackDamage());
    }

    return *this;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap Constructor called" << std::endl;

    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
}

void FragTrap::attack(const std::string &target) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        std::cout << "FragTrap " << getName() << " cannot attack" << std::endl;
        return;
    }

    setEnergyPoint(getEnergyPoint() - 1);

    std::cout
            << "FragTrap " << getName() << " attacks " << target
            << ", causing " << getAttackDamage() << " points of damage!"
            << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        std::cout << "FragTrap " << getName() << " cannot take damage" << std::endl;
        return;
    }

    if (amount > getHitPoint())
        setHitPoint(0);
    else
        setHitPoint(getHitPoint() - amount);

    std::cout
            << "FragTrap " << getName() << " takes " << amount << " damage, "
            << getName() << "'s remaining Hit Point is " << getHitPoint()
            << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        std::cout << "FragTrap " << getName() << " cannot be repaired" << std::endl;
        return;
    }

    setHitPoint(getHitPoint() + amount);
    setEnergyPoint(getEnergyPoint() - 1);

    std::cout
            << "FragTrap " << getName() << " repaired Hit Point worth about " << amount
            << ", " << getName() << "'s remaining Hit Point is " << getHitPoint()
            << std::endl;
}

void FragTrap::highFiveGuys() {
    std::cout << "Gather up! Let's High Five Guys!" << std::endl;
}
