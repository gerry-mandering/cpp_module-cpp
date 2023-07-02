/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:59:17 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/02 19:59:17 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

    ClapTrap dumbAndDumber("DumbAndDumber");

    dumbAndDumber.attack("Firmly Closed Door");
    dumbAndDumber.takeDamage(1);

    dumbAndDumber.attack("Roaring Lion");
    dumbAndDumber.takeDamage(7);

    dumbAndDumber.beRepaired(3);

    dumbAndDumber.attack("Physics Professor who gave him a C grade");
    dumbAndDumber.takeDamage(6);

    dumbAndDumber.beRepaired(3);
    dumbAndDumber.attack("Innocent Citizens");

    return 0;
}