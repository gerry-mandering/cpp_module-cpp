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

Dog::Dog() {
    std::cout << "Dog Constructor called" << std::endl;

    type = "Dog";
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    if (this != &dog)
        type = dog.getType();

    return *this;
}

void Dog::makeSound() {
    std::cout << "I am a Dog! Woof~~!" << std::endl;
}