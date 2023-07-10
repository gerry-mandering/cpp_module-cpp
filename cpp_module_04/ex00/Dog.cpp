/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:24:22 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:24:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

const std::string Dog::DEFAULT_TYPE = "Dog";

Dog::Dog() {
    std::cout << CYN "Dog Constructor called" NC << std::endl;

    type = Dog::DEFAULT_TYPE;
}

Dog::~Dog() {
    std::cout << CYN "Dog Destructor called" NC << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {}

Dog &Dog::operator=(const Dog &dog) {
    if (this != &dog)
        type = dog.getType();

    return *this;
}

void Dog::makeSound() const {
    std::cout << CYN "I am a Dog! Woof~~!" NC << std::endl;
}