/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:24:22 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:24:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

const std::string WrongCat::DEFAULT_TYPE = "WrongCat";

WrongCat::WrongCat() {
    std::cout << GRN "WrongCat Constructor called" NC << std::endl;

    type = WrongCat::DEFAULT_TYPE;
}

WrongCat::~WrongCat() {
    std::cout << GRN "WrongCat Destructor called" NC << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
    if (this != &wrongCat)
        type = wrongCat.getType();

    return *this;
}

void WrongCat::makeSound() const {
    std::cout << GRN "I am a WrongCat! Meow~~?" NC << std::endl;
}
