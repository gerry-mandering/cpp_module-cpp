/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:56:17 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/24 13:56:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void) {}

HumanB::HumanB(const std::string &name) {
    this->setName(name);
}

void HumanB::setName(const std::string &name) {
    this->name = name;
    this->weapon = nullptr;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

const std::string &HumanB::getName() const {
    return this->name;
}

void HumanB::attack() const {
    if (this->weapon)
        std::cout << this->getName() << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->getName() << " attacks with their bare hands" << std::endl;
}
