/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:43 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {

    DiamondTrap dumbAndDumber("DumbAndDumber");

    dumbAndDumber.attack("Firmly Closed Door");
    dumbAndDumber.takeDamage(1);

    dumbAndDumber.attack("Roaring Lion");
    dumbAndDumber.takeDamage(7);

    dumbAndDumber.beRepaired(3);

    dumbAndDumber.attack("Physics Professor who gave him a C grade");
    dumbAndDumber.takeDamage(6);

    dumbAndDumber.beRepaired(3);
    dumbAndDumber.attack("Innocent Citizens");

    dumbAndDumber.guardGate();
    dumbAndDumber.highFiveGuys();
    dumbAndDumber.whoAmI();

    return 0;
}