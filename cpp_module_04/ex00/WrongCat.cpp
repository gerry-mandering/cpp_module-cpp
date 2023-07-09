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
    std::cout << "WrongCat Constructor called" << std::endl;

    type = WrongCat::DEFAULT_TYPE;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
    if (this != &wrongCat)
        type = wrongCat.getType();

    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "I am a WrongCat! Meow~~?" << std::endl;
}
