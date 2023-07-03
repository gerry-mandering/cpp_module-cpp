/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:24:22 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:24:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal Constructor called" << std::endl;

    type = "Animal";
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
    if (this != &animal)
        type = animal.getType();

    return *this;
}

void Animal::makeSound() {
    std::cout << "This creature hasn't been born yet!" << std::endl;
}

const std::string &Animal::getType() const {
    return type;
}