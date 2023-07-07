/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:00:21 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 20:00:21 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {

    FragTrap dumbAndDumber("DumbAndDumber");

    dumbAndDumber.highFiveGuys();

    dumbAndDumber.attack("Firmly Closed Door");
    dumbAndDumber.takeDamage(1);

    dumbAndDumber.attack("Roaring Lion");
    dumbAndDumber.takeDamage(7);

    dumbAndDumber.beRepaired(3);

    dumbAndDumber.attack("Physics Professor who gave him a C grade");
    dumbAndDumber.takeDamage(95);

    dumbAndDumber.beRepaired(3);
    dumbAndDumber.attack("Innocent Citizens");

    dumbAndDumber.highFiveGuys();

    return 0;
}