/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:24:22 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:24:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    ~Dog();
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);

public:
    void makeSound();
};

#endif