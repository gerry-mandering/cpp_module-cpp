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

HumanB::HumanB(const std::string &name) : mName(name), mWeapon(0) {}

void HumanB::setWeapon(Weapon &weapon) {
    mWeapon = &weapon;
}

void HumanB::attack() const {
    if (mWeapon) {
        std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
    } else {
        std::cout << mName << " attacks with their bare hands" << std::endl;
    }
}
