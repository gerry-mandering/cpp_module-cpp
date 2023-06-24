/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:56:17 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/24 13:56:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : weapon(weapon) {
    this->setName(name);
}

void HumanA::setName(const std::string &name) {
    this->name = name;
}

const std::string &HumanA::getName() const {
    return this->name;
}

void HumanA::attack() const {
    std::cout << this->getName() << " attacks with their " << this->weapon.getType() << std::endl;
}