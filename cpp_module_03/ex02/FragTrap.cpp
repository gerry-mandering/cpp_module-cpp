/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap Constructor called" << std::endl;
}

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

FragTrap::FragTrap(const std::string &name) :
        ClapTrap(name, FragTrap::DEFAULT_HIT_POINT, FragTrap::DEFAULT_ENERGY_POINT, FragTrap::DEFAULT_ATTACK_DAMAGE) {
    std::cout << "FragTrap Constructor called" << std::endl;
}

void FragTrap::highFiveGuys() {
    if (!canOperate()) {
        std::cout << "FragTrap " << getName() << " cannot High Five" << std::endl;
        return;
    }

    std::cout << "Gather Up! Let's High Five Guys!" << std::endl;
}
