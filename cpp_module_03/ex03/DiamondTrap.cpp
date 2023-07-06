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

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
    *this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
    if (this != &diamondTrap) {
        mName = diamondTrap.getName();
        mHitPoint = diamondTrap.getHitPoint();
        mEnergyPoint = diamondTrap.getEnergyPoint();
        mAttackDamage = diamondTrap.getAttackDamage();
    }

    return *this;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(), FragTrap(),
                                                    mName(name) {
    std::cout << "DiamondTrap Constructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << mName << " and Also " << ClapTrap::mName << "!" << std::endl;
}