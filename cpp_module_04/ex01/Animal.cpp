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

const std::string Animal::DEFAULT_TYPE = "Animal";

Animal::Animal() {
    std::cout << RED "Animal Constructor called" NC << std::endl;

    type = Animal::DEFAULT_TYPE;
}

Animal::~Animal() {
    std::cout << RED "Animal Destructor called" NC << std::endl;
}

Animal::Animal(const Animal &animal) {
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
    if (this != &animal)
        type = animal.getType();

    return *this;
}

const std::string &Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << RED "This creature hasn't been born yet!" NC << std::endl;
}
