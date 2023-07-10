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
#include "Color.hpp"

class Animal {
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);

public:
    const std::string &getType() const;

public:
    virtual void makeSound() const;

protected:
    std::string type;

private:
    static const std::string DEFAULT_TYPE;
};

#endif
