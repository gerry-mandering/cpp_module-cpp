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

Cat::Cat() {
    std::cout << "Cat Constructor called" << std::endl;

    type = "Cat";
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    if (this != &cat)
        type = cat.getType();

    return *this;
}

void Cat::makeSound() {
    std::cout << "I am a Cat! Meow~~!" << std::endl;
}