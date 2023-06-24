/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:36:32 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/23 21:36:32 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(const std::string &name) {
    this->setName(name);
}

Zombie::~Zombie(void) {
    std::cout << this->getName() << " is now destroyed" << std::endl;
}

void Zombie::setName(const std::string &name) {
    this->mName = name;
}

const std::string &Zombie::getName() const {
    return this->mName;
}

void Zombie::announce() {
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}