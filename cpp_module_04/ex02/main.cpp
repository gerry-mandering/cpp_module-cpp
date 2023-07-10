/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:25:03 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:25:03 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {

    static const int ARRAY_SIZE = 10;
    Animal *animals[ARRAY_SIZE];

    int i;
    for (i = 0; i < ARRAY_SIZE / 2; i++) {
        animals[i] = new Dog();
    }
    for (; i < ARRAY_SIZE; i++) {
        animals[i] = new Cat();
    }

    for (int j = 0; j < ARRAY_SIZE; j++) {
        delete animals[j];
    }

    return 0;
}