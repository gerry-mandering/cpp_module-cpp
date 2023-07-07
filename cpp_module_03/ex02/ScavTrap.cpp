/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap Constructor called" << std::endl;
}

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

ScavTrap::ScavTrap(const std::string &name) :
    ClapTrap(name, ScavTrap::DEFAULT_HIT_POINT, ScavTrap::DEFAULT_ENERGY_POINT, ScavTrap::DEFAULT_ATTACK_DAMAGE) {
    std::cout << "ScavTrap Constructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (!canOperate()) {
        std::cout << "ScavTrap " << getName() << " cannot attack" << std::endl;
        return;
    }

    useEnergy();

    std::cout << "ScavTrap " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    if (!canOperate()) {
        std::cout << "ScavTrap " << getName() << " cannot convert to Gate Keeper Mode" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << getName() << " is now in Gate Keeper Mode!" << std::endl;
}
