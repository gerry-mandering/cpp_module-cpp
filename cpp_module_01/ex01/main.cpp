/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:30:01 by minseok2          +#+    #+#             */
/*   Updated: 2023/06/23 22:30:01 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

    Zombie *zombies = zombieHorde(5, "DanglingHead");

    for (int i = 0; i < 5; i++) {
        zombies->announce();
    }

    delete[] zombies;

    return 0;
}