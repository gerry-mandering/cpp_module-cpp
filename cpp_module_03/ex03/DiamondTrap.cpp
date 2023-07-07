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

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

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

DiamondTrap::DiamondTrap(const std::string &name) :
        ClapTrap(name + "_clap_name", FragTrap::DEFAULT_HIT_POINT, ScavTrap::DEFAULT_ENERGY_POINT, FragTrap::DEFAULT_ATTACK_DAMAGE),
        ScavTrap(),
        FragTrap(),
        mName(name) {
    std::cout << "DiamondTrap Constructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    if (!canOperate()) {
        std::cout << "DiamondTrap " << getName() << " cannot introduce itself" << std::endl;
        return;
    }

    std::cout << "I am " << mName << " and Also " << getName() << "!" << std::endl;
}