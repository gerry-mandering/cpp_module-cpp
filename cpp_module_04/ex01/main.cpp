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

    std::cout << "<Basic Test>" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete dog;//should not create a leak
    delete cat;


    std::cout << "\n\n";


    std::cout << "<Array Test>" << std::endl;

    static const int ARRAY_SIZE = 10;
    Animal *animals[ARRAY_SIZE];

    int i;
    for (i = 0; i < ARRAY_SIZE / 2; i++) {
        std::cout << i << std::endl;
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for (; i < ARRAY_SIZE; i++) {
        std::cout << i << std::endl;
        animals[i] = new Cat();
        std::cout << std::endl;
    }

    for (int j = 0; j < ARRAY_SIZE; j++) {
        std::cout << j << std::endl;
        delete animals[j];
        std::cout << std::endl;
    }

    return 0;
}