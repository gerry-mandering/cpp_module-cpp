/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:30:01 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/23 22:30:01 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(const std::string &name) : mName(name) {}

Zombie::~Zombie(void) {
    std::cout << mName << " is now destroyed" << std::endl;
}

void Zombie::setName(const std::string &name) {
    mName = name;
}

const std::string &Zombie::getName() const {
    return mName;
}

void Zombie::announce() {
    std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}