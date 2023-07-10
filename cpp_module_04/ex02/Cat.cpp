/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:24:22 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:24:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

const std::string Cat::DEFAULT_TYPE = "Cat";

Cat::Cat() {
    std::cout << GRN "Cat Constructor called" NC << std::endl;

    type = Cat::DEFAULT_TYPE;
    mBrain = new Brain();
}

Cat::~Cat() {
    std::cout << GRN "Cat Destructor called" NC << std::endl;

    delete mBrain;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
    mBrain = cat.mBrain;
}

Cat &Cat::operator=(const Cat &cat) {
    if (this != &cat) {
        type = cat.getType();
        mBrain = cat.mBrain;
    }

    return *this;
}

void Cat::makeSound() const {
    std::cout << GRN "I am a Cat! Meow~~!" NC << std::endl;
}