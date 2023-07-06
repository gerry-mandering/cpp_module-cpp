/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:43 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:43 by minseok2         ###   ########.fr       */
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

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20){
    std::cout << "ScavTrap Constructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (getHitPoint() == 0 || getEnergyPoint() == 0) {
        printErrorMessage(ATTACK_FAIL);
        return;
    }

    useEnergy();

    std::cout << "ScavTrap " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate Keeper Mode!" << std::endl;
}

void ScavTrap::printErrorMessage(eErrorMessage errorMessage) const {
    switch (errorMessage) {
        case ATTACK_FAIL:
            std::cout << "ScavTrap " << getName() << " cannot attack" << std::endl;
            break;
        case TAKE_DAMAGE_FAIL:
            std::cout << "ScavTrap " << getName() << " cannot take damage" << std::endl;
            break;
        case BE_REPAIRED_FAIL:
            std::cout << "ScavTrap " << getName() << " cannot be repaired" << std::endl;
            break;
    }
}
