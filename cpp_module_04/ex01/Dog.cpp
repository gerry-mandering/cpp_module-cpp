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
    std::cout << "Dog Constructor called" << std::endl;

    type = Dog::DEFAULT_TYPE;
    mBrain = new Brain();
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;

    delete mBrain;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    mBrain = dog.mBrain;
}

Dog &Dog::operator=(const Dog &dog) {
    if (this != &dog) {
        mBrain = dog.mBrain;
        type = dog.getType();
    }

    return *this;
}

void Dog::makeSound() const {
    std::cout << "I am a Dog! Woof~~!" << std::endl;
}