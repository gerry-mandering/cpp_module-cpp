/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:24:22 by minseok2          +#+    #+#             */
/*   Updated: 2023/07/03 13:24:22 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
protected:
    std::string type;

protected:
    const std::string &getType() const;

public:
    Animal();
    ~Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);

public:
    void makeSound();
};

#endif
