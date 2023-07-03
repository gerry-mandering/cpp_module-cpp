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

Zombie::Zombie(const std::string &name) : mName(name) {}

Zombie::~Zombie(void) {
    std::cout << mName << " is now destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void) {}
